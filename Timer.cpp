#include "Timer.h"

Timer::Timer(double timeLimit) : timerValue(0), timeLimit(timeLimit), executePermission(0), executable(true) {}
Timer::Timer() : timerValue(0), timeLimit(0), executePermission(0), executable(false) {}
void Timer::incrementValue(double timeGain)
{
	timerValue += timeGain;
	if (executable && timerValue >= timeLimit)
	{
		timerValue -= timeLimit;
		executePermission = 1;
	}
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
