#include "DefeatEngine.h"

DefeatEngine::DefeatEngine(SDL_Window* window, SDL_Renderer* renderer) : defeatPainter(new DefeatPainter(window, renderer)) {}

void DefeatEngine::start()
{
	while (isGameCommandUndefined())
	{
		defeatPainter->drawScreen();
		handleDefeatEvents();
	}
}

void DefeatEngine::handleDefeatEvents()
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
				setGameCommand(Game::Command::restartLevel);
				break;
			case SDLK_n:
				setGameCommand(Game::Command::backToMenu);
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

DefeatEngine::~DefeatEngine()
{
	delete defeatPainter;
}