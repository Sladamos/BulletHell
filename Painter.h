#pragma once
#include <stdio.h>
#include <string.h>
#include "MathPoint.h"
#include "Game.h"
#include "./SDL2-2.0.10/include/SDL.h"
#include "./SDL2-2.0.10/include/SDL_main.h"
#define bigCenterVector MathVector(MathPoint(-(strlen(text) * bigLetterSize / 2), 0))

class GameObject;
class Painter
{
public:
	Painter(SDL_Window* window, SDL_Renderer* renderer);
	virtual ~Painter();
	virtual void drawScreen() = 0;
	void drawObject(SDL_Surface* objectBmp, const MathPoint& coords);
	
	static constexpr int statsWidth = (Game::screenWidth / 4);
protected:
	void drawString(const MathPoint& coords);
	void drawBigString(const MathPoint& coords);
	void drawFillRectangle(const MathPoint& coords, int width, int height, Uint32 color);
	void updateTextureAndRenderer();
	void clearScreen();

	char text[Game::maxTextLength];
	int blackColor, redColor, blueColor;
	static constexpr int smallLetterSize = 8;
	static constexpr int bigLetterSize = 32;
	static constexpr int lettersInRow = 16;
private:
	void drawPixel(const MathPoint& coords, Uint32 color);
	void drawLine(const MathPoint& coords, int length, int inclinationDegrees, Uint32 color);
	void drawRectangle(const MathPoint& coords, int width, int height, Uint32 outlineColor, Uint32 fillColor);
	void drawOutlineRectangle(const MathPoint& coords, int width, int height, Uint32 color);
	void setColors();

	SDL_Surface* screen;
	SDL_Surface* charset;
	SDL_Surface* bigCharset;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* scrtex;
};

