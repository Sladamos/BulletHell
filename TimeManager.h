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
	double getTimeGain();
private:
	void calculateTimeGain();

	double timeGain;
	int firstTicker, secondTicker;
	static std::list<Timer*> timers;
};

