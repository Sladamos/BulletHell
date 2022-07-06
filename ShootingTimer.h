#pragma once
#include "Timer.h"
class ShootingTimer : public Timer
{
public:
	ShootingTimer(double timeLimit);
	bool isPermissionToShoot();
	void resetTimer() override;
private:
	void executeAction() override;
	bool shootingPermission;
};

