#pragma once
#include "Timer.h"
class AnimationTimer : public Timer
{
public:
	AnimationTimer(double timeLimit, int numberOfFrames);
	int getCurrentFrameNumber();
	void resetTimer() override;
private:
	void executeAction() override;
	void calculateFrames();
	void checkCountingDirection();

	int currentFrame, numberOfFrames;
	bool increaseFrames;
};

