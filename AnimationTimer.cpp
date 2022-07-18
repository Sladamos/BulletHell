#include "AnimationTimer.h"

AnimationTimer::AnimationTimer(double timeLimit, int numberOfFrames) : Timer(timeLimit/numberOfFrames), numberOfFrames(numberOfFrames), 
				currentFrame(0), increaseFrames(true) {}

int AnimationTimer::getCurrentFrameNumber()
{
	return currentFrame;
}

void AnimationTimer::resetTimer()
{
	currentFrame = 0;
	increaseFrames = true;
}

void AnimationTimer::executeAction()
{
	checkCountingDirection();
	calculateFrames();
}

void AnimationTimer::checkCountingDirection()
{
	if (currentFrame == numberOfFrames - 1)
		increaseFrames = false;
	else if (currentFrame == 0)
		increaseFrames = true;
}

void AnimationTimer::calculateFrames()
{
	if (increaseFrames)
		currentFrame++;
	else
		currentFrame--;
}