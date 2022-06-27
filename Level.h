#pragma once
#include "TimeManager.h"
#include "Painter.h"
#include "Player.h"
class Level
{
public:
	Level();
	~Level();
	Timer* getLevelTimer();
	std::list<GameObject*> getGameObjects();
	void startLevel();
private:
	void handleLevelEvents();
	void createGameObjects();
	void performGameObjectsActions(double timeGain);

	Timer* levelTimer;
	Painter* levelPainter;
	TimeManager* timeManager;
	Player* player;
	std::list<GameObject*> gameObjects;
	bool levelInProgress;
};


