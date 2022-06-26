#include "TimeManager.h"
#include"./SDL2-2.0.10/include/SDL.h"
#include"./SDL2-2.0.10/include/SDL_main.h"

std::list<Timer*> TimeManager::timers = std::list<Timer*>();

TimeManager::TimeManager() : firstTicker(SDL_GetTicks()), secondTicker(firstTicker) {}

void TimeManager::addTimer(Timer* timer)
{
	timers.push_back(timer);
}

void TimeManager::increaseAndExecuteTimers()
{
	double timeGain = calculateTimeGain();
	for (Timer* timer : timers)
	{
		timer->incrementValue(timeGain);
		timer->executeIfPossible();
	}
}

double TimeManager::calculateTimeGain()
{
	secondTicker = SDL_GetTicks();
	double delta = (secondTicker - firstTicker) * 0.001;
	firstTicker = secondTicker;
	return delta;
}

TimeManager::~TimeManager()
{
	timers.clear();
}
