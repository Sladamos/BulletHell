#include "VictoryEngine.h"

VictoryEngine::VictoryEngine(SDL_Window* window, SDL_Renderer* renderer) : victoryPainter(new VictoryPainter(window, renderer)) {}

void VictoryEngine::start()
{
	while (isGameCommandUndefined())
	{
		victoryPainter->drawScreen();
		handleVictoryEvents();
	}
}

void VictoryEngine::handleVictoryEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) 
	{
		switch (event.type) 
		{
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_y:
				setGameCommand(Game::Command::saveScore);
				break;
			case SDLK_n:
				setGameCommand(Game::Command::createNextLevel);
				break;
			case SDLK_ESCAPE:
				setGameCommand(Game::Command::exitGame);
				break;
			}
			break;
		case SDL_QUIT:
			setGameCommand(Game::Command::exitGame);
		};
	}
}

VictoryEngine::~VictoryEngine()
{
	delete victoryPainter;
}