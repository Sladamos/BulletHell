#pragma once
class Timer
{
public:
	Timer(double timeLimit);
	Timer();
	void executeIfPossible();
	void incrementValue(double timeGain);
	void resetTimer();
	double getTimerValue();
	double getTimeLimit();
protected:
	virtual void executeAction();
private:
	double timerValue, timeLimit;
	bool executePermission, executable;
};

