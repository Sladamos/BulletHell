#include "HittingTimer.h"

HittingTimer::HittingTimer(double timeLimit) : Timer(timeLimit), hittingPermission(false) {}

bool HittingTimer::isPermissionToHit()
{
	return hittingPermission;
}

void HittingTimer::executeAction()
{
	hittingPermission = true;
}