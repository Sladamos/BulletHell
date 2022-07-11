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
	void circleShooting();
	void arrowShooting();
	void laserShooting();
	ShootingTimer* getShootingTimer();
protected:
	void shootIfPossible(void(Shootable::*shootingPattern)());
	virtual void createBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed) = 0;
	void setViewingAngle(double newValue);
private:
	void createLaser();

	double viewingAngle;
	ShootingTimer* shootingTimer;
};

