#pragma once
#include "TimeManager.h"
#include "Painter.h"
class Level
{
public:
	Level(int level);
	~Level();
	Timer* getLevelTimer();
private:
	void handleLevelEvents();
	void etiLoop();

	Timer* levelTimer;
	Painter* levelPainter;
	TimeManager* timeManager;
	bool levelInProgress;
};


