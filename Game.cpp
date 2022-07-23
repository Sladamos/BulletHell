#include <ctime>
#include "Game.h"
#include "MenuEngine.h"
#include "VictoryEngine.h"
#include "DefeatEngine.h"
#include "ScoreSaverEngine.h"
#include "HighScoresEngine.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Level4.h"

Game::Game() : gameInProgress(true), currentInterfaceElement(nullptr), currentLevel(0)
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

void Game::handleCommand(Command command)
{
	switch (command)
	{
	case Command::exitGame: default:
		gameInProgress = false;
		break;
	case Command::backToMenu:
		createMenu();
		break;
	case Command::createSelectedLevel:
		currentLevel = dynamic_cast<MenuEngine*>(currentInterfaceElement)->getSelectedLevel();
		createLevel(currentLevel);
		break;
	case Command::saveScore:
		createScoreSaver();
		break;
	case Command::drawHighScores:
		createHighScores();
		break;
	case Command::restartLevel:
		createLevel(currentLevel);
		break;
	case Command::victory:
		createVictory();
		break;
	case Command::defeat:
		createDefeat();
		break;
	case Command::createNextLevel:
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

void Game::createHighScores()
{
	clearInterfaceElement();
	currentInterfaceElement = new HighScoresEngine(window, renderer);
}

void Game::createScoreSaver()
{
	clearInterfaceElement();
	currentInterfaceElement = new ScoreSaverEngine(window, renderer);
}

void Game::createDefeat()
{
	clearInterfaceElement();
	currentInterfaceElement = new DefeatEngine(window, renderer);
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
