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
	MathVector distanceBetweenText(MathPoint(0, 2.5*bigLetterSize));
	MathPoint textCoords(Game::screenWidth/2, bigLetterSize);
	sprintf(text, "Menu");
	drawBigString(MathPoint(textCoords).moveByVector(bigCenterVector));
	sprintf(text, "Start a new game:");
	drawBigString(MathPoint(textCoords.moveByVector(distanceBetweenText*1.5)).moveByVector(bigCenterVector));
	for (int i = 1; i <= Game::numberOfStages; i++)
	{
		sprintf(text, "%i - Stage %i", i, i);
		drawBigString(MathPoint(textCoords.moveByVector(distanceBetweenText)).moveByVector(bigCenterVector));
	}
	sprintf(text, "H - High Scores");
	drawBigString(MathPoint(textCoords.moveByVector(distanceBetweenText)).moveByVector(bigCenterVector));
	sprintf(text, "ESC - Quit game");
	drawBigString(MathPoint(textCoords.moveByVector(distanceBetweenText)).moveByVector(bigCenterVector));
}