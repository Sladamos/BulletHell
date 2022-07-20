#pragma once
#include "Painter.h"
class DefeatPainter : public Painter
{
public:
	DefeatPainter(SDL_Window* window, SDL_Renderer* renderer);
	void drawScreen() override;
private:
	void drawDefeatInfo();
};

