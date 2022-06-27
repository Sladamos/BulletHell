#pragma once
#include "TimeManager.h"
#include "Painter.h"
#include "Player.h"
class Level
{
public:
	Level(SDL_Window* window, SDL_Renderer* renderer);
	~Level();
	Timer* getLevelTimer();
	std::list<GameObject*> getGameObjects();
	void startLevel();
private:
	void handleLevelEvents();
	void createGameObjects();
	void performGameObjectsActions(double timeGain);
	void handlePlayerMovement(const SDL_Event& event);

	Timer* levelTimer;
	Painter* levelPainter;
	TimeManager* timeManager;
	Player* player;
	std::list<GameObject*> gameObjects;
	bool levelInProgress;
};


