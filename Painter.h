#pragma once
#include "./SDL2-2.0.10/include/SDL.h"
#include "./SDL2-2.0.10/include/SDL_main.h"
#include "FpsTimer.h"
#include "GameObject.h"
#include "Point.h"
#include "Constans.h"

class Level;
class Painter
{
public:
	Painter(Level* level);
	~Painter();
	void drawScreen();
	void drawObject(SDL_Surface* objectBmp, const Point& coords);
private:
	void setColors();
	void createWindowAndRenderer();
	void drawString(const Point& coords, const char* text);
	void drawPixel(const Point& coords, Uint32 color);
	void drawLine(const Point& coords, int length, int inclinationDegrees, Uint32 color);
	void drawRectangle(const Point& coords, int width, int height, Uint32 outlineColor, Uint32 fillColor);
	void drawOutlineRectangle(const Point& coords, int width, int height, Uint32 color);
	void drawFillRectangle(const Point& coords, int width, int height, Uint32 color);
	void drawStatistics();
	void addFpsTimer();
	void printGameObjects();

	SDL_Surface* screen, *charset;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* scrtex;

	int BLACK, RED, BLUE;
	FpsTimer* fpsTimer;
	char text[MAX_TEXT_SIZE];
	Level* level;
};

