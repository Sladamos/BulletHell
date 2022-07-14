#include "ShootingTimer.h"

ShootingTimer::ShootingTimer() : Timer(), shootingPermission(true) {}

ShootingTimer::ShootingTimer(double timeLimit) : Timer(timeLimit), shootingPermission(true) {}

bool ShootingTimer::isPermissionToShoot()
{
	return shootingPermission;
}

void ShootingTimer::resetTimer()
{
	Timer::resetTimer();
	shootingPermission = false;
}

void ShootingTimer::executeAction()
{
	shootingPermission = true;
}