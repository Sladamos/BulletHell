#pragma once
#include "Game.h"
#include "TimeManager.h"
#include "LevelPainter.h"
class Level;
class LevelEngine
{
public:
	LevelEngine(Level* currentLevel, SDL_Window* window, SDL_Renderer* renderer);
	~LevelEngine();
	void start();
private:
	void performGameObjectsActions(double timeGain);
	void handleLevelEvents();
	void handlePlayerMovement(const SDL_Event& event);
	void actualizeGameCommand();

	Level* currentLevel;
	LevelPainter* levelPainter;
	TimeManager* timeManager;
};

