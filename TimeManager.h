#pragma once
#include <list>
#include "Timer.h"
class TimeManager
{
public:
	TimeManager();
	~TimeManager();
	static void addTimer(Timer* timer);
	void removeTimer(Timer* timer);
	void increaseAndExecuteTimers();
	void startCounting();
	double getTimeGain();
private:
	void calculateTimeGain();

	double timeGain;
	int firstTicker, secondTicker;
	static std::list<Timer*> timers;
};

