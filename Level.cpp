#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime>
#include "MathPoint.h"
#include "Level.h"
#include "BmpManager.h"
#include "ShapesManager.h"
#include "VerticalLevelBorder.h"
#include "HorizontalLevelBorder.h"
#include "Bullet.h"
#include "HpBonus.h"
#include"./SDL2-2.0.10/include/SDL.h"
#include"./SDL2-2.0.10/include/SDL_main.h"

std::list<GameObject*> Level::gameObjects = std::list<GameObject*>();

Level::Level(SDL_Window* window, SDL_Renderer* renderer) : levelResult(LevelResult::unknown), levelTimer(new Timer()),
						  timeManager(new TimeManager()), levelPainter(new LevelPainter(this, window, renderer))
{
	timeManager->addTimer(levelTimer);
	srand(time(NULL));
}

Player* Level::getPlayer()
{
	for (GameObject* object : gameObjects)
	{
		if (object->isPlayer())
			return dynamic_cast<Player*>(object);
	}
	return nullptr;
}

std::list<Enemy*> Level::getEnemies()
{
	return enemies;
}

LevelResult Level::getResult()
{
	return levelResult;
}

void Level::addBullet(Bullet* newBullet)
{
	gameObjects.push_back(newBullet);
}

void Level::addEnemy(Enemy* enemy)
{
	gameObjects.push_back(enemy);
	enemies.push_back(enemy);
}

void Level::createGameObjects()
{
	gameObjects.push_back(new Player("./gfx/player_an_1", std::vector<MathPoint>{MathPoint(-40, -40), MathPoint(-40, 40), MathPoint(40, 40), MathPoint(40, -40)}));
	gameObjects.push_back(new HpBonus("./gfx/hpBonus", std::vector<MathPoint>{MathPoint(-45, -45), MathPoint(-45, 45), MathPoint(45, 45), MathPoint(45, -45)}));
	createEnemies();
	createLevelBorders();
	objectsWithoutBullets = getGameObjectsWithoutBullets();
}

void Level::createLevelBorders()
{
	int wallSize = Constants::wallSize, levelHeight = Constants::levelHeight, levelWidth = Constants::levelWidth;
	gameObjects.push_back(new HorizontalLevelBorder("./gfx/horizontalBorder", MathPoint(levelWidth/2, wallSize/2), std::vector<MathPoint>{MathPoint(-levelWidth/2, -wallSize/2), MathPoint(-levelWidth/2, wallSize/2), MathPoint(levelWidth/2, wallSize/2), MathPoint(levelWidth/2, -wallSize/2)}));
	gameObjects.push_back(new VerticalLevelBorder("./gfx/VerticalBorder", MathPoint(levelWidth-wallSize/2, levelHeight/2), std::vector<MathPoint>{MathPoint(-wallSize/2, -levelHeight/2), MathPoint(-wallSize/2, levelHeight/2), MathPoint(wallSize/2, levelHeight/2), MathPoint(wallSize/2, -levelHeight/2)}));
	gameObjects.push_back(new HorizontalLevelBorder("./gfx/horizontalBorder", MathPoint(levelWidth/2, levelHeight - wallSize/2), std::vector<MathPoint>{MathPoint(-levelWidth/2, -wallSize/2), MathPoint(-levelWidth/2, wallSize/2), MathPoint(levelWidth/2, wallSize/2), MathPoint(levelWidth/2, -wallSize/2)}));
	gameObjects.push_back(new VerticalLevelBorder("./gfx/VerticalBorder", MathPoint(wallSize/2, levelHeight/2), std::vector<MathPoint>{MathPoint(-wallSize/2, -levelHeight/2), MathPoint(-wallSize/2, levelHeight/2), MathPoint(wallSize/2, levelHeight/2), MathPoint(wallSize/2, -levelHeight/2)}));
}

void Level::handleLevelEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_UP: case SDLK_LEFT: case SDLK_DOWN: case SDLK_RIGHT:
				handlePlayerMovement(event);
				break;
			case SDLK_f:
				getPlayer()->setShootingPermission(true);
				break;
			case SDLK_ESCAPE:
				levelResult = LevelResult::aborted;
				break;
			case SDLK_n:
				levelResult = LevelResult::restarted;
				break;
			}
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_UP: case SDLK_LEFT: case SDLK_DOWN: case SDLK_RIGHT:
				handlePlayerMovement(event);
				break;
			case SDLK_f:
				getPlayer()->setShootingPermission(false);
			}
			break;
		case SDL_QUIT:
			levelResult = LevelResult::aborted;
		};
	};
}

void Level::handlePlayerMovement(const SDL_Event& event)
{
	Player* player = getPlayer();
	switch (event.type) 
	{
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			player->setVerticalSpeed(-1.0 * Player::playerSpeedMultiplier);
			break;
		case SDLK_LEFT:
			player->setHorizontalSpeed(-1.0 * Player::playerSpeedMultiplier);
			break;
		case SDLK_DOWN:
			player->setVerticalSpeed(1.0 * Player::playerSpeedMultiplier);
			break;
		case SDLK_RIGHT:
			player->setHorizontalSpeed(1.0 * Player::playerSpeedMultiplier);
		}
		break;
	case SDL_KEYUP:
		if(player->stoppedVertically(event))
			player->setVerticalSpeed(0.0);
		if (player->stoppedHorizontally(event))
			player->setHorizontalSpeed(0.0);
	}
	player->updateViewingAngle();
}

std::list<GameObject*> Level::getGameObjects()
{
	return gameObjects;
}

Timer* Level::getLevelTimer()
{
	return levelTimer;
}

void Level::startLevel()
{
	createGameObjects();
	timeManager->startCounting();
	while (isLevelInProgress())
	{
		levelPainter->drawScreen();
		timeManager->increaseAndExecuteTimers();
		handleLevelEvents();
		performGameObjectsActions(timeManager->getTimeGain());
		actualizeLevelResult();
	}
}

void Level::performGameObjectsActions(double timeGain)
{

	for (auto it = gameObjects.begin(); it != gameObjects.end();)
	{
		GameObject* object = *it++;
		if (object->shouldBeDestroyed())
			destroyGameObject(object);
		else
		{
			object->action(timeGain);
			object->checkCollisions(objectsWithoutBullets, timeGain);
		}
	}
}

void Level::destroyGameObject(GameObject* gameObject)
{
	if (gameObject->isEnemy())
	{
		enemies.remove(dynamic_cast<Enemy*>(gameObject));
		timeManager->removeTimer(dynamic_cast<Enemy*>(gameObject)->getShootingTimer());
	}
	if(!gameObject->isBullet())
		objectsWithoutBullets.remove(gameObject);
	gameObjects.remove(gameObject);
	delete gameObject;
}

void Level::actualizeLevelResult()
{
	if (getPlayer()->getHitpoints() <= 0)
		levelResult = LevelResult::lost;
	else if (areAllEnemiesDead())
		levelResult = LevelResult::won;
}

std::list<GameObject*> Level::getGameObjectsWithoutBullets()
{
	std::list<GameObject*> objectsWithoutBullets;
	std::copy_if(gameObjects.begin(), gameObjects.end(), std::back_inserter(objectsWithoutBullets),
		[](GameObject* object) {return dynamic_cast<Bullet*>(object) == nullptr; });
	return objectsWithoutBullets;
}

bool Level::areAllEnemiesDead()
{
	bool enemiesLose = true;
	for (Enemy* enemy : enemies)
	{
		if (enemy->getHitpoints() > 0)
			enemiesLose = false;
	}

	return enemiesLose;
}

bool Level::isLevelInProgress()
{
	return levelResult == LevelResult::unknown;
}

Level::~Level()
{
	for (GameObject* object : gameObjects)
		delete object;
	gameObjects.clear();
	BmpManager::freeBitmaps();
	ShapesManager::freeShapes();
	delete levelTimer;
	delete levelPainter;
	delete timeManager;
}