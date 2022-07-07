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

Enemy* Level::getEnemy()
{
	for (GameObject* object : gameObjects)
	{
		if (object->isEnemy())
			return dynamic_cast<Enemy*>(object);
	}
	return nullptr;
}

LevelResult Level::getResult()
{
	return levelResult;
}

void Level::addBullet(Bullet* newBullet)
{
	gameObjects.push_back(newBullet);
}

void Level::createGameObjects()
{
	gameObjects.push_back(new Player("./gfx/eti", std::vector<MathPoint>{MathPoint(-45, -45), MathPoint(-45, 45), MathPoint(45, 45), MathPoint(45, -45)}));
	createEnemy();
	createLevelBorders();
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

	//TODO: player->updateLookingDirection(); - implement shooting
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
	}
}

void Level::performGameObjectsActions(double timeGain)
{
	std::list<GameObject*> objectsWithoutBullets;
	std::copy_if(gameObjects.begin(), gameObjects.end(), std::back_inserter(objectsWithoutBullets),
	[](GameObject* object) {return dynamic_cast<Bullet*>(object) == nullptr; });

	for (auto it = gameObjects.begin(); it != gameObjects.end();)
	{
		GameObject* object = *it++;
		if (object->shouldBeDestroyed())
		{
			delete object;
			gameObjects.remove(object);
		}
		else
		{
			object->action(timeGain);
			object->checkCollisions(objectsWithoutBullets, timeGain);
		}
	}
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