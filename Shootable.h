#pragma once
#include "ShootingTimer.h"
class MathPoint;
class Shootable
{
public:
	Shootable();
	Shootable(double shootingTimeLimit);
	virtual ~Shootable();
	void randomShooting();
	void multipleShooting();
	void circleShooting();
	void arrowShooting();
	void laserShooting();
protected:
	void shootIfPossible(void(Shootable::*shootingPattern)());
	void setViewingAngle(double newValue);
private:
	void createLaser();
	virtual void createBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed) = 0;

	double viewingAngle;
	ShootingTimer* shootingTimer;
};

