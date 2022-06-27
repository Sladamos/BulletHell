#pragma once
#include "Timer.h"
class FpsTimer : public Timer
{
public:
	FpsTimer(double timeLimit);
	void incrementFrames();
	double getFps();
private:
	void executeAction() override;

	int frames;
	double fps;
};

