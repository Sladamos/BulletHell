#pragma once
#include <list>
#include "Timer.h"
class TimeManager
{
public:
	TimeManager();
	~TimeManager();
	static void addTimer(Timer* timer);
	void increaseAndExecuteTimers();
	//clear timers, reset timers
private:
	double calculateTimeGain();

	int firstTicker, secondTicker;
	static std::list<Timer*> timers;
};

