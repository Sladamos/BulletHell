#include "ScoreSaverPainter.h"
#include "ScoreSaverEngine.h"

ScoreSaverPainter::ScoreSaverPainter(const std::string& nickname, SDL_Window* window, SDL_Renderer* renderer) : Painter(window, renderer), currentNick(nickname) {}

void ScoreSaverPainter::drawScreen()
{
	clearScreen();
	drawSaverInfo();
	updateTextureAndRenderer();
}

void ScoreSaverPainter::drawSaverInfo()
{
	MathVector distanceBetweenText(MathPoint(0, 2 * bigLetterSize));
	MathPoint textCoords(Game::screenWidth / 2, Game::screenHeight / 4);

	sprintf(text, "Nickname: ");
	drawBigString(MathPoint(textCoords).moveByVector(MathVector(MathPoint(-ScoreSaverEngine::maxNickLength * bigLetterSize,0))));
	sprintf(text, currentNick.c_str());
	drawBigString(MathPoint(textCoords));
	sprintf(text, "Press ENTER to save your score");
	drawBigString(MathPoint(textCoords.moveByVector(distanceBetweenText)).moveByVector(bigCenterVector));
	sprintf(text, "Press ESC to cancel");
	drawBigString(MathPoint(textCoords.moveByVector(distanceBetweenText)).moveByVector(bigCenterVector));
}