#pragma once
#include "Timer.h"
class ScoreMagnitudeTimer : public Timer
{
public:
	ScoreMagnitudeTimer(double timeLimit);
	double getMagnitude();
	void increaseMagnitude();
private:
	void executeAction() override;

	double magnitude;
	constexpr static double defaultMagnitude = 1;
};

