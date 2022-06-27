#pragma once
#include "LevelResult.h"
#include"./SDL2-2.0.10/include/SDL.h"
#include"./SDL2-2.0.10/include/SDL_main.h"
class Level;
class Game
{
public:
	Game();
	~Game();
private:
	void createLevel(int levelNumber);
	void startGame();
	void handleLevelResult(LevelResult levelresult);
	void createGui();

	SDL_Window* window;
	SDL_Renderer* renderer;
	Level* currentlyPlayedLevel;
	int currentLevel;
	bool gameInProgress;
	//bool gameLaunched; //TODO: implement menu
};

