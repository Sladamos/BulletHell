#include <cmath>
#include "HighScoresEngine.h"
#include "FilesOperator.h"

HighScoresEngine::HighScoresEngine(SDL_Window* window, SDL_Renderer* renderer) : pageNumber(1), scores(FilesOperator::loadScores())
{
	maxNumberOfPages = scores.size() == 0 ? 1 : ceil(static_cast<double>(scores.size()) / HighScoresPainter::maxNumberOfDisplayedScores);
	scoresPainter = new HighScoresPainter(scoresToPrint, pageNumber, maxNumberOfPages, window, renderer);
	updateScoresToPrint();
}

void HighScoresEngine::start()
{
	while (isGameCommandUndefined())
	{
		scoresPainter->drawScreen();
		handleHighScoresEvents();
	}
}

void HighScoresEngine::handleHighScoresEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_LEFT:
				if (pageNumber > 1)
				{
					pageNumber--;
					updateScoresToPrint();
				}
				break;
			case SDLK_RIGHT:
				if (pageNumber < maxNumberOfPages)
				{
					pageNumber++;
					updateScoresToPrint();
				}
				break;
			case SDLK_ESCAPE:
				setGameCommand(GameCommand::backToMenu);
				break;
			}
			break;
		case SDL_QUIT:
			setGameCommand(GameCommand::exitGame);
		};
	}
}

void HighScoresEngine::updateScoresToPrint()
{
	scoresToPrint.clear();
	for (int i = (pageNumber-1)*HighScoresPainter::maxNumberOfDisplayedScores; i < pageNumber*HighScoresPainter::maxNumberOfDisplayedScores && i < scores.size(); i++)
		scoresToPrint.push_back(scores[i]);
}

HighScoresEngine::~HighScoresEngine()
{
	delete scoresPainter;
}

