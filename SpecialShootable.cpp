#define _USE_MATH_DEFINES
#include <cmath>
#include "SpecialShootable.h"
#include "MathPoint.h"
#include "GameObject.h"

SpecialShootable::SpecialShootable(double shootingTimeLimit)
{
	shootingTimer = new ShootingTimer(shootingTimeLimit);
}

void SpecialShootable::shootSpecialIfPossible(void(SpecialShootable::* shootingPattern)())
{
	if (shootingTimer->isPermissionToShoot())
	{
		(this->*shootingPattern)();
		shootingTimer->resetTimer();
	}
}

void SpecialShootable::randomSpecialShooting()
{
	double randomAngle = rand() % 360 * M_PI / 180.00;
	MathPoint position = dynamic_cast<GameObject*>(this)->getPosition();
	createSpecialBullet(position, cos(randomAngle), sin(randomAngle));
}

SpecialShootable::~SpecialShootable()
{
	delete shootingTimer;
}