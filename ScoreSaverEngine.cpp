#include "ScoreSaverEngine.h"
#include "FilesOperator.h"
#include "Player.h"

ScoreSaverEngine::ScoreSaverEngine(SDL_Window* window, SDL_Renderer* renderer) : saverPainter(new ScoreSaverPainter(nickname, window, renderer)) {}

void ScoreSaverEngine::start()
{
	while (isGameCommandUndefined())
	{
		saverPainter->drawScreen();
		handleSaverEvents();
	}
}

void ScoreSaverEngine::handleSaverEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event) && event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym >= SDLK_a && event.key.keysym.sym <= SDLK_z && nickname.length() < maxNickLength)
		{
			if (nickname.length() == 0)
				nickname.push_back(event.key.keysym.sym - SDLK_a + 'A');
			else
				nickname.push_back(event.key.keysym.sym - SDLK_a + 'a');
		}
		else if (event.key.keysym.sym == SDLK_BACKSPACE && nickname.length() <= maxNickLength && nickname.length() > 0)
				nickname.pop_back();
		else if (event.key.keysym.sym == SDLK_ESCAPE)
			setGameCommand(GameCommand::victory);
		else if (event.key.keysym.sym == SDLK_RETURN && nickname.length() > 0)
		{
			setGameCommand(GameCommand::createNextLevel);
			FilesOperator::saveScore(Score(nickname, Player::getScoreValue()));
		}
	}
}

ScoreSaverEngine::~ScoreSaverEngine()
{
	delete saverPainter;
}