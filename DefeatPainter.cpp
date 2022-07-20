#include "DefeatPainter.h"
#include "MathVector.h"
#define centerVector MathVector(MathPoint(-(strlen(text) * bigLetterSize / 2), 0))

DefeatPainter::DefeatPainter(SDL_Window* window, SDL_Renderer* renderer) : Painter(window, renderer) {}

void DefeatPainter::drawScreen()
{
	clearScreen();
	drawDefeatInfo();
	updateTextureAndRenderer();
}

void DefeatPainter::drawDefeatInfo()
{
	MathVector distanceBetweenText(MathPoint(0, 2 * bigLetterSize));
	MathPoint textCoords(Game::screenWidth / 2, bigLetterSize);
	sprintf(text, "You died, try again?");
	drawBigString(MathPoint(textCoords).moveByVector(centerVector));
	sprintf(text, "Y - Yes, try again");
	drawBigString(MathPoint(textCoords.moveByVector(distanceBetweenText * 2)).moveByVector(centerVector));
	sprintf(text, "N - No, back to menu");
	drawBigString(MathPoint(textCoords.moveByVector(distanceBetweenText)).moveByVector(centerVector));
	sprintf(text, "ESC - Quit game");
	drawBigString(MathPoint(textCoords.moveByVector(distanceBetweenText)).moveByVector(centerVector));
}