#include "Level.h"
#include "BmpManager.h"
#include"./SDL2-2.0.10/include/SDL.h"
#include"./SDL2-2.0.10/include/SDL_main.h"

Level::Level(SDL_Window* window, SDL_Renderer* renderer) : levelInProgress(true), levelTimer(new Timer()),
						  timeManager(new TimeManager()), levelPainter(new Painter(this, window, renderer))
{ //TODO: make abstract (with enemies)
	timeManager->addTimer(levelTimer);
	createGameObjects();
}

void Level::createGameObjects()
{
	player = new Player("eti");
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
				//TODO: player->updateLookingDirection();
				break;
			case SDLK_ESCAPE:
				levelInProgress = false;	//TODO: level result
				break;
			}
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_UP: case SDLK_LEFT: case SDLK_DOWN: case SDLK_RIGHT:
				handlePlayerMovement(event);
				//TODO: player->updateLookingDirection();
				break;
			}
			break;
		case SDL_QUIT:
			levelInProgress = false;
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
	while (levelInProgress)
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
		object->action(timeGain);
}

Level::~Level()
{
	for (GameObject* object : gameObjects)
		delete object;
	BmpManager::freeBitmaps();
	delete levelTimer;
	delete levelPainter;
	delete timeManager;
}