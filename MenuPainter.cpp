#include "MenuPainter.h"

MenuPainter::MenuPainter(SDL_Window* window, SDL_Renderer* renderer) : Painter(window, renderer) {}

void MenuPainter::drawScreen()
{
	clearScreen();
	drawMenuInfo();
	updateTextureAndRenderer();
}

void MenuPainter::drawMenuInfo()
{
	MathPoint textCoords(Game::screenWidth/2, bigLetterSize);
	sprintf(text, "Menu");
	drawBigString(MathPoint(textCoords).moveByVector(bigCenterVector));
	sprintf(text, "Start a new game:");
	drawBigString(MathPoint(textCoords.moveByVector(distanceBetweenBigTextRows *1.5)).moveByVector(bigCenterVector));
	for (int i = 1; i <= Game::numberOfStages; i++)
	{
		sprintf(text, "%i - Stage %i", i, i);
		drawBigString(MathPoint(textCoords.moveByVector(distanceBetweenBigTextRows)).moveByVector(bigCenterVector));
	}
	sprintf(text, "H - High Scores");
	drawBigString(MathPoint(textCoords.moveByVector(distanceBetweenBigTextRows)).moveByVector(bigCenterVector));
	sprintf(text, "ESC - Quit game");
	drawBigString(MathPoint(textCoords.moveByVector(distanceBetweenBigTextRows)).moveByVector(bigCenterVector));
}