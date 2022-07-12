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

	static constexpr int maxTextLength = 128;
	static constexpr int screenWidth = 1024;
	static constexpr int screenHeight = 768;
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

