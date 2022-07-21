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
				setGameCommand(GameCommand::saveScore);
				break;
			case SDLK_n:
				setGameCommand(GameCommand::createNextLevel);
				break;
			case SDLK_ESCAPE:
				setGameCommand(GameCommand::exitGame);
				break;
			}
			break;
		case SDL_QUIT:
			setGameCommand(GameCommand::exitGame);
		};
	}
}

VictoryEngine::~VictoryEngine()
{
	delete victoryPainter;
}