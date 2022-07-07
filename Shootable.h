#pragma once
#include "ShootingTimer.h"
class MathPoint;
class Shootable
{
public:
	Shootable(double shootingTimeLimit);
	virtual ~Shootable();
	void randomShooting();
protected:
	void shootIfPossible(void(Shootable::*shootingPattern)());
	virtual void createBullet(const MathPoint& position, int radius, double horizontalSpeed, double verticalSpeed) = 0;
private:

	ShootingTimer* shootingTimer;
};

