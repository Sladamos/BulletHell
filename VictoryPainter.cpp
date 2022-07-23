#include "VictoryPainter.h"

VictoryPainter::VictoryPainter(SDL_Window* window, SDL_Renderer* renderer) : Painter(window, renderer) {}

void VictoryPainter::drawScreen()
{
	clearScreen();
	drawVictoryInfo();
	updateTextureAndRenderer();
}

void VictoryPainter::drawVictoryInfo()
{
	MathPoint textCoords(Game::screenWidth / 2, bigLetterSize);
	sprintf(text, "You won, save current score??");
	drawBigString(MathPoint(textCoords).moveByVector(bigCenterVector));
	sprintf(text, "Y - Yes, save and go next");
	drawBigString(MathPoint(textCoords.moveByVector(distanceBetweenBigTextRows * 2)).moveByVector(bigCenterVector));
	sprintf(text, "N - Don't save and go next");
	drawBigString(MathPoint(textCoords.moveByVector(distanceBetweenBigTextRows)).moveByVector(bigCenterVector));
	sprintf(text, "ESC - Quit game");
	drawBigString(MathPoint(textCoords.moveByVector(distanceBetweenBigTextRows)).moveByVector(bigCenterVector));
}