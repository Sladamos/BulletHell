#include "ScoreMagnitudeTimer.h"

ScoreMagnitudeTimer::ScoreMagnitudeTimer(double timeLimit) : Timer(timeLimit), magnitude(defaultMagnitude) {}

double ScoreMagnitudeTimer::getMagnitude()
{
	return magnitude;
}

void ScoreMagnitudeTimer::increaseMagnitude()
{
	magnitude += 0.15;
}

void ScoreMagnitudeTimer::executeAction()
{
	magnitude = defaultMagnitude;
}

	