#pragma once
#include "Painter.h"
#include "FpsTimer.h"

class Level;
class LevelPainter : public Painter
{
public:
	LevelPainter(Level* level, SDL_Window* window, SDL_Renderer* renderer);
	~LevelPainter();
	virtual void drawScreen() override;
private:
	void printGameObjects();
	void drawStatisticsPanel();
	void drawStatistics();
	void drawBackground();
	void drawHealthBars();
	void drawPlayerHealthBar();
	void drawEnemyHealthBar();
	void addFpsTimer();
	bool bothSidesOfConflictAreAlive();

	SDL_Surface* background;
	Level* level;
	FpsTimer* fpsTimer;
	const int playerHpBarHeight = 50, playerHpBarFrameSize = 3;
};

