#include "InvicibilityTimer.h"
#include "ShootingTimer.h"

InvicibilityTimer::InvicibilityTimer(double timeLimit) : Timer(timeLimit), ableToTakeDamage(true) {}

bool InvicibilityTimer::canBeDamaged()
{
	return ableToTakeDamage;
}

void InvicibilityTimer::resetTimer()
{
	Timer::resetTimer();
	ableToTakeDamage = false;
}

void InvicibilityTimer::executeAction()
{
	ableToTakeDamage = true;
}