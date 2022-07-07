#define _USE_MATH_DEFINES
#include <cmath>
#include "Shootable.h"
#include "TimeManager.h"
#include "HolyBullet.h"
#include "UnholyBullet.h"

Shootable::Shootable(double shootingTimeLimit)
{
	shootingTimer = new ShootingTimer(shootingTimeLimit);
	TimeManager::addTimer(shootingTimer);
}

void Shootable::shootIfPossible(void(Shootable::*shootingPattern)())
{
	if (shootingTimer->isPermissionToShoot())
	{
		(this->*shootingPattern)();
		shootingTimer->resetTimer();
	}
}

void Shootable::randomShooting()
{
	double angle = rand() % 360 * M_PI / 180.00;
	MathPoint position = dynamic_cast<GameObject*>(this)->getPosition();
	createBullet(position, 13, cos(angle) * Bullet::bulletSpeedMultiplier, sin(angle) * Bullet::bulletSpeedMultiplier);
}

Shootable::~Shootable()
{
	delete shootingTimer;
}