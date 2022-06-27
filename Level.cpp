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
			if (event.key.keysym.sym == SDLK_ESCAPE) levelInProgress = false;
			else if (event.key.keysym.sym == SDLK_UP) player->setSpeed(2.0);
			else if (event.key.keysym.sym == SDLK_DOWN) player->setSpeed(0.3);
			break;
		case SDL_KEYUP:
			player->setSpeed(1.0);
			break;
		case SDL_QUIT:
			levelInProgress = false;
		};
	};
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