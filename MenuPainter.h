#pragma once
#include "Painter.h"
class MenuPainter : public Painter
{
public:
	MenuPainter(SDL_Window* window, SDL_Renderer* renderer);
	void drawScreen() override;
private:
	void drawMenuInfo();
};

