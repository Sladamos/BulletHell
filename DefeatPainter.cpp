#include "DefeatPainter.h"

DefeatPainter::DefeatPainter(SDL_Window* window, SDL_Renderer* renderer) : Painter(window, renderer) {}

void DefeatPainter::drawScreen()
{
	clearScreen();
	drawDefeatInfo();
	updateTextureAndRenderer();
}

void DefeatPainter::drawDefeatInfo()
{
	MathPoint textCoords(Game::screenWidth / 2, bigLetterSize);
	sprintf(text, "You died, try again?");
	drawBigString(MathPoint(textCoords).moveByVector(bigCenterVector));
	sprintf(text, "Y - Yes, try again");
	drawBigString(MathPoint(textCoords.moveByVector(distanceBetweenBigTextRows * 2)).moveByVector(bigCenterVector));
	sprintf(text, "N - No, back to menu");
	drawBigString(MathPoint(textCoords.moveByVector(distanceBetweenBigTextRows)).moveByVector(bigCenterVector));
	sprintf(text, "ESC - Quit game");
	drawBigString(MathPoint(textCoords.moveByVector(distanceBetweenBigTextRows)).moveByVector(bigCenterVector));
}