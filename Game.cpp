#include <ctime>
#include "Game.h"
#include "MenuEngine.h"
#include "VictoryEngine.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Level4.h"

Game::Game() : gameInProgress(true), currentLevel(0), currentInterfaceElement(nullptr)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	srand(time(NULL));
	createGui();
	createMenu();
	startGame();
}

void Game::startGame()
{
	while (gameInProgress)
	{
		currentInterfaceElement->start();
		handleCommand(currentInterfaceElement->getGameCommand());
	}
}

void Game::handleCommand(GameCommand command)
{
	switch (command)
	{
	case GameCommand::exitGame:
		gameInProgress = false;
		break;
	case GameCommand::backToMenu:
		createMenu();
		break;
	case GameCommand::createSelectedLevel:
		currentLevel = dynamic_cast<MenuEngine*>(currentInterfaceElement)->getSelectedLevel();
		//No break here -> its important! (also its important to keep that command before restartLevel)
	case GameCommand::restartLevel:  case GameCommand::levelLost:
		createLevel(currentLevel);
		break;
	case GameCommand::victory:
		createVictory();
		break;
	case GameCommand::createNextLevel:
		createLevel(++currentLevel);
	}
}

void Game::createGui()
{
	SDL_CreateWindowAndRenderer(screenWidth, screenHeight, 0, &window, &renderer);
	SDL_SetWindowTitle(window, "BulletHell");
	SDL_RenderSetLogicalSize(renderer, screenWidth, screenHeight);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_ShowCursor(SDL_DISABLE);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
}

void Game::createVictory()
{
	clearInterfaceElement();
	currentInterfaceElement = new VictoryEngine(window, renderer);
}

void Game::createMenu()
{
	clearInterfaceElement();
	currentInterfaceElement = new MenuEngine(window, renderer);
}

void Game::createLevel(int levelNumber)
{
	clearInterfaceElement();
	switch (levelNumber)
	{
	case 1:
		currentInterfaceElement = new Level1(window, renderer);
		break;
	case 2:
		currentInterfaceElement = new Level2(window, renderer);
		break;
	case 3:
		currentInterfaceElement = new Level3(window, renderer);
		break;
	case 4:
		currentInterfaceElement = new Level4(window, renderer);
		break;
	default:
		gameInProgress = false;
	}
}

void Game::clearInterfaceElement()
{
	if (currentInterfaceElement != nullptr)
	{
		delete currentInterfaceElement;
		currentInterfaceElement = nullptr;
	}
}

Game::~Game()
{
	clearInterfaceElement();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
