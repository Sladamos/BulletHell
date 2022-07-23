#pragma once
#include "Timer.h"
class ChangesTimer : public Timer
{
public:
	ChangesTimer(double timeLimit);
	bool isPermissionToChange();
	void resetTimer() override;
private:
	void executeAction() override;

	bool changingPermission;
};

