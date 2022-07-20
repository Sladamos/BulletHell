#include "MenuEngine.h"

MenuEngine::MenuEngine(SDL_Window* window, SDL_Renderer* renderer) : menuPainter(new MenuPainter(window, renderer)) {}

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
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_1:
				selectedLevel = 1;
				setGameCommand(GameCommand::createSelectedLevel);
				break;
			case SDLK_2:
				selectedLevel = 2;
				setGameCommand(GameCommand::createSelectedLevel);
				break;
			case SDLK_3:
				selectedLevel = 3;
				setGameCommand(GameCommand::createSelectedLevel);
				break;
			case SDLK_4:
				selectedLevel = 4;
				setGameCommand(GameCommand::createSelectedLevel);
				break;
			case SDLK_ESCAPE:
				setGameCommand(GameCommand::exitGame);
				break;
			}
			break;
		case SDL_QUIT:
			setGameCommand(GameCommand::exitGame);
		};
	};
}

MenuEngine::~MenuEngine()
{
	delete menuPainter;
}