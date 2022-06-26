#include "Level.h"
#include"./SDL2-2.0.10/include/SDL.h"
#include"./SDL2-2.0.10/include/SDL_main.h"

Level::Level(int level) : levelInProgress(true), levelTimer(new Timer()), timeManager(new TimeManager()), levelPainter(new Painter(this))	//z argumentem level cos takiego
{
	timeManager->addTimer(levelTimer);
	etiLoop();
}

void Level::handleLevelEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE) levelInProgress = false;
			//else if (event.key.keysym.sym == SDLK_UP) player->setSpeed(2.0);
			//else if (event.key.keysym.sym == SDLK_DOWN) player->setSpeed(0.3);
			break;
		//case SDL_KEYUP:
			//player->setSpeed(1.0);
			//break;
		case SDL_QUIT:
			levelInProgress = false;
		};
	};
}

Timer* Level::getLevelTimer()
{
	return levelTimer;
}

void Level::etiLoop()
{
	while (levelInProgress) 
	{
		levelPainter->drawScreen();
		//distance += etiSpeed * delta;
		timeManager->increaseAndExecuteTimers();
		handleLevelEvents();
	};	//lista obiektów w grze -> jak inrange to print, jak movable to move
}

Level::~Level()
{
	//clearBitmaps
	delete levelTimer;
	delete levelPainter;
	delete timeManager;
}