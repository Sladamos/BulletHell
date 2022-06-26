#pragma once
#include "./SDL2-2.0.10/include/SDL.h"
#include "./SDL2-2.0.10/include/SDL_main.h"
#include "FpsTimer.h"
#define MAX_TEXT_SIZE 128

class Level;
class Painter
{
public:
	Painter(Level* level);
	~Painter();
	void drawScreen();
private:
	void setColors();
	void createWindowAndRenderer();
	void drawString(int xCoord, int yCoord, const char* text, SDL_Surface* charset);
	void drawPixel(int xCoord, int yCoord, Uint32 color);
	void drawLine(int xCoord, int yCoord, int length, int inclinationDegrees, Uint32 color);
	void drawRectangle(int xCoord, int yCoord, int width, int height, Uint32 outlineColor, Uint32 fillColor);
	void drawSprite(SDL_Surface* sprite, int xCoord, int yCoord);
	void drawStatistics();
	void addFpsTimer();

	SDL_Surface* screen, *charset;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* scrtex;

	int BLACK, RED, BLUE;
	FpsTimer* fpsTimer;
	char text[MAX_TEXT_SIZE];
	Level* level;
};

