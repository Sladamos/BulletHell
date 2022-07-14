#pragma once
#include "ShootingTimer.h"
class MathPoint;
class SpecialShootable
{
public:
	SpecialShootable(double shootingTimeLimit);
	virtual ~SpecialShootable();
	void randomSpecialShooting();
protected:
	void shootSpecialIfPossible(void(SpecialShootable::* shootingPattern)());
private:
	virtual void createSpecialBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed) = 0;

	ShootingTimer* shootingTimer;
};

