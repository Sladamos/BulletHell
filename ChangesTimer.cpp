#include "ChangesTimer.h"

ChangesTimer::ChangesTimer(double timeLimit) : Timer(timeLimit), changingPermission(false) {}

bool ChangesTimer::isPermissionToChange()
{
	return changingPermission;
}

void ChangesTimer::resetTimer()
{
	Timer::resetTimer();
	changingPermission = false;
}

void ChangesTimer::executeAction()
{
	changingPermission = true;
}