#pragma once
#include <list>
#include "Painter.h"
#include "Score.h"
class HighScoresPainter : public Painter
{
public:
	HighScoresPainter(const std::list<Score>& scores, const int& pageNumber, int maxNumberOfPages, SDL_Window* window, SDL_Renderer* renderer);
	void drawScreen() override;

	static constexpr int maxNumberOfDisplayedScores = 6;
private:
	void drawScoresInfo();
	void drawScores();

	const std::list<Score>& scoresToPrint;
	const int& pageNumber;
	int maxNumberOfPages;
};
