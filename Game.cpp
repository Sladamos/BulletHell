#include "Game.h"
#include "Painter.h"
#include "Level1.h"
#include "Level2.h"

Game::Game() : gameInProgress(true), currentLevel(1), currentlyPlayedLevel(nullptr)	//TODO: implement menu ; move currentlvl into new/load Game
{
	SDL_Init(SDL_INIT_EVERYTHING);
	createGui();
	createLevel(currentLevel);	//TEMP: remove after implementing menu (with new game etc)
	startGame();
}

void Game::startGame()
{
	while (gameInProgress)
	{
		currentlyPlayedLevel->startLevel();
		handleLevelResult(currentlyPlayedLevel->getResult());	
	}
}

void Game::handleLevelResult(LevelResult levelResult)
{
	switch (levelResult)
	{
	case LevelResult::aborted: 
		gameInProgress = false;
		break;
	case LevelResult::restarted:  case LevelResult::lost:
		createLevel(currentLevel);
		break;
	case LevelResult::won:
		createLevel(++currentLevel);
	}
	//TODO: implement menu
	//FUTURE IMPLEMENTATION TODO: implement more levels
	//createLevel(++currentLevel); - next level
	//if you won (ask for save score and after that ask for next or back to menu) (insta delete previous)
	//if you lost (back to menu or try again) (delete if back to menu)
	//if you aborted (back to menu and delete current)
}

void Game::createGui()
{
	SDL_CreateWindowAndRenderer(screenWidth, screenHeight, 0, &window, &renderer);
	SDL_SetWindowTitle(window, "Szablon SDL2");
	SDL_RenderSetLogicalSize(renderer, screenWidth, screenHeight);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_ShowCursor(SDL_DISABLE);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
}

void Game::createLevel(int levelNumber)
{
	if (currentlyPlayedLevel != nullptr)
	{
		delete currentlyPlayedLevel;
		currentlyPlayedLevel = nullptr;
	}
	switch (levelNumber)
	{
	case 1:
		currentlyPlayedLevel = new Level1(window, renderer);
		break;
	case 2:
		currentlyPlayedLevel = new Level2(window, renderer);
		break;
	default:
		gameInProgress = false;
	}
}

Game::~Game()
{
	if (currentlyPlayedLevel != nullptr)
		delete currentlyPlayedLevel;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
