#pragma once
#include "Painter.h"
class VictoryPainter : public Painter
{
public:
	VictoryPainter(SDL_Window* window, SDL_Renderer* renderer);
	void drawScreen() override;
private:
	void drawVictoryInfo();
};

