#include "HighScoresPainter.h"

HighScoresPainter::HighScoresPainter(const std::list<Score>& scores, const int& pageNumber, int maxNumberOfPages, SDL_Window* window, SDL_Renderer* renderer) :
	Painter(window, renderer), scoresToPrint(scores), pageNumber(pageNumber), maxNumberOfPages(maxNumberOfPages) {}

void HighScoresPainter::drawScreen()
{
	clearScreen();
	drawScoresInfo();
	drawScores();
	updateTextureAndRenderer();
}

void HighScoresPainter::drawScoresInfo()
{
	MathPoint textCoords(Game::screenWidth / 2, 3 * bigLetterSize / 2);
	sprintf(text, "\032 ESC");
	drawBigString(MathPoint(15, 3*bigLetterSize/2));
	sprintf(text, "High Scores");
	drawBigString(MathPoint(textCoords).moveByVector(bigCenterVector));
	sprintf(text, "\032 Page %d/%d \033", pageNumber, maxNumberOfPages);
	drawBigString(MathPoint(Game::screenWidth / 2, Game::screenHeight).moveByVector(bigCenterVector).moveByVector(-distanceBetweenBigTextRows));
}

void HighScoresPainter::drawScores()
{
	MathVector distanceBetweenText(MathPoint(0, 2 * bigLetterSize));
	MathPoint textCoords(15, 4 * bigLetterSize);
	for (Score score : scoresToPrint)
	{
		sprintf(text, score.toString().c_str());
		drawBigString(MathPoint(textCoords.moveByVector(distanceBetweenText)));
	}
}