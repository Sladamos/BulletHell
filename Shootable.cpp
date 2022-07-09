#define _USE_MATH_DEFINES
#include <cmath>
#include "Shootable.h"
#include "TimeManager.h"
#include "HolyBullet.h"
#include "UnholyBullet.h"

Shootable::Shootable(double shootingTimeLimit) : viewingAngle(0)
{
	shootingTimer = new ShootingTimer(shootingTimeLimit);
	TimeManager::addTimer(shootingTimer);
}

ShootingTimer* Shootable::getShootingTimer()
{
	return shootingTimer;
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
	double randomAngle = rand() % 360 * M_PI / 180.00;
	MathPoint position = dynamic_cast<GameObject*>(this)->getPosition();
	createBullet(position, cos(randomAngle) * Bullet::bulletSpeedMultiplier, sin(randomAngle) * Bullet::bulletSpeedMultiplier);
}

void Shootable::multipleShooting()
{
	const int numberOfBulletsInOneShoot = 5;
	const double angleBetweenBullets = 20 * M_PI / 180.00;
	double bulletAngle = getViewingAngle() * M_PI / 180.00  - numberOfBulletsInOneShoot / 2 * angleBetweenBullets;
	MathPoint position = dynamic_cast<GameObject*>(this)->getPosition();
	for (int i = 0; i < numberOfBulletsInOneShoot; i++)
	{
		createBullet(position, cos(bulletAngle) * Bullet::bulletSpeedMultiplier, sin(bulletAngle) * Bullet::bulletSpeedMultiplier);
		bulletAngle += angleBetweenBullets;
	}
}

double Shootable::getViewingAngle()
{
	return viewingAngle;
}

void Shootable::updateViewingAngle()
{
}

Shootable::~Shootable()
{
	delete shootingTimer;
}