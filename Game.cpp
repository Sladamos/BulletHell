#include "Game.h"
#include "Level.h"

Game::Game() : gameInProgress(true), currentLevel(1)	//TODO: implement menu ; move currentlvl into new/load Game
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
		gameInProgress = false;	//TEMP: remove after implement handleResult
		//handleLevelResult(level->getResult)	//TODO: implement win/lose condition -> do smth with gameInProgress
	}
}

void Game::handleLevelResult(LevelResult levelResult)
{
	//FUTURE IMPLEMENTATION
	//createLevel(++currentLevel); - next level
	//level->reset() (better destro and create with same number)
	//if you won (ask for save score and after that ask for next or back to menu) (insta delete previous)
	//if you lost (back to menu or try again) (delete if back to menu)
	//if you aborted (back to menu and delete current)
}

void Game::createGui()
{
	SDL_CreateWindowAndRenderer(Constans::screenWidth, Constans::screenHeight, 0, &window, &renderer);
	SDL_SetWindowTitle(window, "Szablon SDL2");
	SDL_RenderSetLogicalSize(renderer, Constans::screenWidth, Constans::screenHeight);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_ShowCursor(SDL_DISABLE);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
}

void Game::createLevel(int levelNumber)
{
	switch (levelNumber)
	{
	case '1':
		//currentlyPlayedLevel = new Level1(window, renderer);
		//break;
	case '2':
		//currentlyPlayedLevel = new Level2(window, renderer);
		//break;
	default:
		currentlyPlayedLevel = new Level(window, renderer);
	}
}

Game::~Game()
{
	delete currentlyPlayedLevel;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
