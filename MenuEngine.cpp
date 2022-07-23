#include "MenuEngine.h"

MenuEngine::MenuEngine(SDL_Window* window, SDL_Renderer* renderer) : menuPainter(new MenuPainter(window, renderer)), selectedLevel(1) {}

int MenuEngine::getSelectedLevel()
{
	return selectedLevel;
}

void MenuEngine::start()
{
	while (isGameCommandUndefined())
	{
		menuPainter->drawScreen();
		handleMenuEvents();
	}
}

void MenuEngine::handleMenuEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) 
	{
		switch (event.type) 
		{
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_1:
				selectedLevel = 1;
				setGameCommand(Game::Command::createSelectedLevel);
				break;
			case SDLK_2:
				selectedLevel = 2;
				setGameCommand(Game::Command::createSelectedLevel);
				break;
			case SDLK_3:
				selectedLevel = 3;
				setGameCommand(Game::Command::createSelectedLevel);
				break;
			case SDLK_4:
				selectedLevel = 4;
				setGameCommand(Game::Command::createSelectedLevel);
				break;
			case SDLK_h:
				setGameCommand(Game::Command::drawHighScores);
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

MenuEngine::~MenuEngine()
{
	delete menuPainter;
}