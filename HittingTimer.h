#pragma once
#include "Timer.h"
class HittingTimer : public Timer
{
public:
	HittingTimer(double timeLimit);
	bool isPermissionToHit();
private:
	void executeAction() override;
	bool hittingPermission;
};

