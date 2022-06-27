#include "TimeManager.h"
#include"./SDL2-2.0.10/include/SDL.h"
#include"./SDL2-2.0.10/include/SDL_main.h"

std::list<Timer*> TimeManager::timers = std::list<Timer*>();

TimeManager::TimeManager() : firstTicker(0), secondTicker(0), timeGain(0.0) {}

void TimeManager::addTimer(Timer* timer)
{
	timers.push_back(timer);
}

void TimeManager::startCounting()
{
	firstTicker = SDL_GetTicks();
}

double TimeManager::getTimeGain()
{
	return timeGain;
}

void TimeManager::increaseAndExecuteTimers()
{
	calculateTimeGain();
	for (Timer* timer : timers)
	{
		timer->incrementValue(timeGain);
		timer->executeIfPossible();
	}
}

void TimeManager::calculateTimeGain()
{
	secondTicker = SDL_GetTicks();
	timeGain = (secondTicker - firstTicker) * 0.001;
	firstTicker = secondTicker;
}

TimeManager::~TimeManager()
{
	timers.clear();
}
