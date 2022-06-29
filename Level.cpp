#include <vector>
#include "Point.h"
#include "Level.h"
#include "BmpManager.h"
#include "PolygonsManager.h"
#include"./SDL2-2.0.10/include/SDL.h"
#include"./SDL2-2.0.10/include/SDL_main.h"

Level::Level(SDL_Window* window, SDL_Renderer* renderer) : levelResult(LevelResult::unknown), levelTimer(new Timer()),
						  timeManager(new TimeManager()), levelPainter(new Painter(this, window, renderer))
{ //TODO: make abstract (with enemies)
	timeManager->addTimer(levelTimer);
	createGameObjects();
}

Player* Level::getPlayer()
{
	return player;
}

LevelResult Level::getResult()
{
	return levelResult;
}

void Level::createGameObjects()
{
	player = new Player("./gfx/eti", std::vector<Point>{Point(-45,-45), Point(-45,45), Point(45,-45), Point(45,45)});
	gameObjects.push_back(player);
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

	//TODO: player->updateLookingDirection();
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
	for (GameObject* object : gameObjects)
	{
		object->action(timeGain);
		if (object->isMoveable())
			object->checkLevelBorderCollision();
	}
	//TODO: object->checkObjectsCollisions(); GameObject virtual void;
}

bool Level::isLevelInProgress()
{
	return levelResult == LevelResult::unknown;
}

Level::~Level()
{
	for (GameObject* object : gameObjects)
		delete object;
	BmpManager::freeBitmaps();
	PolygonsManager::freePolygons();
	delete levelTimer;
	delete levelPainter;
	delete timeManager;
}