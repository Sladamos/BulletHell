#pragma once
#include "Point.h"
#include "Constants.h"
#include "./SDL2-2.0.10/include/SDL.h"
#include "./SDL2-2.0.10/include/SDL_main.h"

class GameObject;
class Painter
{
public:
	Painter(SDL_Window* window, SDL_Renderer* renderer);
	virtual ~Painter();
	virtual void drawScreen() = 0;
	void drawObject(SDL_Surface* objectBmp, const Point& coords);
protected:
	void drawString(const Point& coords);
	void drawFillRectangle(const Point& coords, int width, int height, Uint32 color);
	void updateTextureAndRenderer();

	SDL_Surface* screen;
	char text[Constants::maxTextLength];
	int blackColor, redColor, blueColor;
private:
	void drawPixel(const Point& coords, Uint32 color);
	void drawLine(const Point& coords, int length, int inclinationDegrees, Uint32 color);
	void drawRectangle(const Point& coords, int width, int height, Uint32 outlineColor, Uint32 fillColor);
	void drawOutlineRectangle(const Point& coords, int width, int height, Uint32 color);
	void setColors();

	SDL_Surface* charset;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* scrtex;
};

