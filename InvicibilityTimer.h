#pragma once
#include "Timer.h"
class InvicibilityTimer : public Timer
{
public:
	InvicibilityTimer(double timeLimit);
	bool canBeDamaged();
	void resetTimer() override;
private:
	void executeAction() override;
	bool ableToTakeDamage;
};

