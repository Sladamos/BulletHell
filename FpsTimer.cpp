#include "FpsTimer.h"

FpsTimer::FpsTimer(double timeLimit) : Timer(timeLimit), frames(0), fps(0) {}

double FpsTimer::getFps()
{
	return fps;
}

void FpsTimer::incrementFrames()
{
	frames++;
}

void FpsTimer::executeAction()
{
	fps = frames/getTimeLimit();
	frames = 0;
}