#pragma once
#include <vector>
#include <list>
#include "InterfaceElement.h"
#include "HighScoresPainter.h"
class HighScoresEngine : public InterfaceElement
{
public:
	HighScoresEngine(SDL_Window* window, SDL_Renderer* renderer);
	~HighScoresEngine();
	void start() override;
private:
	void handleHighScoresEvents();
	void updateScoresToPrint();

	HighScoresPainter* scoresPainter;
	std::list<Score> scoresToPrint;
	std::vector<Score> scores;
	int pageNumber;
	int maxNumberOfPages;
};

