#pragma once
#include "InterfaceElement.h"
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
	static constexpr int numberOfStages = 4;
private:
	void createLevel(int levelNumber);
	void createGui();
	void createMenu();
	void startGame();
	void handleCommand(GameCommand command);
	void clearInterfaceElement();

	SDL_Window* window;
	SDL_Renderer* renderer;
	InterfaceElement* currentInterfaceElement;
	int currentLevel;
	bool gameInProgress;
};

