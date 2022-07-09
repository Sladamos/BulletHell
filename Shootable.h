#pragma once
#include "ShootingTimer.h"
class MathPoint;
class Shootable
{
public:
	Shootable(double shootingTimeLimit);
	virtual ~Shootable();
	void randomShooting();
	void multipleShooting();
	ShootingTimer* getShootingTimer();
protected:
	void shootIfPossible(void(Shootable::*shootingPattern)());
	virtual void createBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed) = 0;
	virtual void updateViewingAngle();

	double viewingAngle;
private:
	double getViewingAngle();

	ShootingTimer* shootingTimer;
};

