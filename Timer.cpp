#include "Timer.h"
#include "TimeManager.h"

Timer::Timer(double timeLimit) : timerValue(0), timeLimit(timeLimit), executePermission(0), executable(true) 
{
	TimeManager::addTimer(this);
}

Timer::Timer() : timerValue(0), timeLimit(0), executePermission(0), executable(false) 
{
	TimeManager::addTimer(this);
}

void Timer::incrementValue(double timeGain)
{
	timerValue += timeGain;
	if (executable && timerValue >= timeLimit)
	{
		timerValue -= timeLimit;
		executePermission = 1;
	}
}

void Timer::resetTimer()
{
	timerValue = 0;
	executePermission = 0;
}

double Timer::getTimerValue()
{
	return timerValue;
}

double Timer::getTimeLimit()
{
	return timeLimit;
}

void Timer::executeIfPossible()
{
	if (executePermission)
	{
		executePermission = 0;
		executeAction();
	}
}

void Timer::executeAction() {}

Timer::~Timer()
{
	TimeManager::removeTimer(this);
}