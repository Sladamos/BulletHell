#pragma once
#include "FpsTimer.h"
#include "Point.h"
#include "Constants.h"
#include "./SDL2-2.0.10/include/SDL.h"
#include "./SDL2-2.0.10/include/SDL_main.h"

class GameObject;
class Level;
class Painter
{
public:
	Painter(Level* level, SDL_Window* window, SDL_Renderer* renderer);
	~Painter();
	void drawScreen();
	void drawObject(SDL_Surface* objectBmp, const Point& coords);
private:
	void setColors();
	void drawString(const Point& coords);
	void drawPixel(const Point& coords, Uint32 color);
	void drawLine(const Point& coords, int length, int inclinationDegrees, Uint32 color);
	void drawRectangle(const Point& coords, int width, int height, Uint32 outlineColor, Uint32 fillColor);
	void drawOutlineRectangle(const Point& coords, int width, int height, Uint32 color);
	void drawFillRectangle(const Point& coords, int width, int height, Uint32 color);
	void drawStatistics();
	void drawWalls();
	void drawBackground();
	void addFpsTimer();
	void printGameObjects();

	SDL_Surface *screen, *charset, *background;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* scrtex;
	FpsTimer* fpsTimer;
	Level* level;
	char text[Constants::maxTextLength];
	int blackColor, redColor, blueColor;
};

