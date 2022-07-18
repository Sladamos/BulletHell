#define _USE_MATH_DEFINES
#include <cmath>
#include "Shootable.h"
#include "Bullet.h"
#include "MathVector.h"

Shootable::Shootable() : viewingAngle(0)
{
	shootingTimer = new ShootingTimer();
}

Shootable::Shootable(double shootingTimeLimit) : viewingAngle(0)
{
	shootingTimer = new ShootingTimer(shootingTimeLimit);
}

void Shootable::shootIfPossible(void(Shootable::* shootingPattern)())
{
	if (shootingTimer->isPermissionToShoot())
	{
		(this->*shootingPattern)();
		shootingTimer->resetTimer();
	}
}

void Shootable::placeBullet()
{
	MathPoint shooterPosition = dynamic_cast<GameObject*>(this)->getPosition();
	const double randomAngle = rand() % 360 * M_PI / 180.00;
	constexpr int distanceFromShooter = 80;
	MathVector spaceVector = MathVector(MathPoint(distanceFromShooter + rand() % Bullet::maxRange, 0));
	createBullet(MathPoint(shooterPosition).moveByVector(spaceVector).rotate(randomAngle, shooterPosition), 0,0);
}

void Shootable::circleShooting()
{
	MathPoint position = dynamic_cast<GameObject*>(this)->getPosition();
	constexpr int bulletsInCircle = 18, spaceSize = 4;
	constexpr double angleBetweenBullets = M_PI * 2 / bulletsInCircle;
	const int spacePosition = rand() % (bulletsInCircle - spaceSize + 1);

	for (int i = 0; i < bulletsInCircle; i++)
		if (i < spacePosition || i >= spacePosition + spaceSize)
			createBullet(position, cos(angleBetweenBullets * i), sin(angleBetweenBullets * i));
}

void Shootable::randomShooting()
{
	const double randomAngle = rand() % 360 * M_PI / 180.00;
	MathPoint position = dynamic_cast<GameObject*>(this)->getPosition();
	createBullet(position, cos(randomAngle), sin(randomAngle));
}

void Shootable::multipleShooting()
{
	constexpr int numberOfBulletsInOneShoot = 5;
	constexpr double angleBetweenBullets = 20 * M_PI / 180.00;
	double bulletAngle = viewingAngle * M_PI / 180.00 - numberOfBulletsInOneShoot / 2 * angleBetweenBullets;
	MathPoint position = dynamic_cast<GameObject*>(this)->getPosition();

	for (int i = 0; i < numberOfBulletsInOneShoot; i++)
	{
		createBullet(position, cos(bulletAngle), sin(bulletAngle));
		bulletAngle += angleBetweenBullets;
	}
}

void Shootable::laserShooting()
{
	constexpr int numberOfLasers = 4;
	for (int i = 0; i < numberOfLasers; i++)
		createLaser();
}

void Shootable::createLaser()
{
	constexpr int bulletsInLaser = 5, space = 30;
	const double laserAngle = rand() % 360 * M_PI / 180.00;
	MathPoint shooterPosition = dynamic_cast<GameObject*>(this)->getPosition(), edgePosition = MathPoint(shooterPosition);
	MathVector spaceVector = MathVector(MathPoint(space, 0));
	for (int i = 0; i < bulletsInLaser; i++)
	{
		createBullet(MathPoint(edgePosition).rotate(laserAngle, shooterPosition), cos(laserAngle), sin(laserAngle));
		edgePosition.moveByVector(spaceVector);
	}
}

void Shootable::arrowShooting()
{
	constexpr int bulletsInArrow = 9, verticalSpace = 30, horizontalSpace = 15, distanceFromShooter = 30;
	static_assert(bulletsInArrow % 2 == 1, "Number of bullets in an arrow has to be odd");
	MathPoint shooterPosition = dynamic_cast<GameObject*>(this)->getPosition();
	MathPoint edgePosition = MathPoint(shooterPosition).moveByVector(MathVector(MathPoint(distanceFromShooter, -bulletsInArrow / 2 * verticalSpace)));
	MathVector diagonalVector = MathVector(MathPoint(horizontalSpace, verticalSpace));
	const double arrowAngle = rand() % 360 * M_PI / 180.00;

	for (int i = bulletsInArrow / 2; i > 0; i--)
	{
		createBullet(MathPoint(edgePosition).rotate(arrowAngle, shooterPosition), cos(arrowAngle), sin(arrowAngle));
		createBullet(MathPoint(edgePosition).moveByVector(MathVector(MathPoint(0, 2 * i * verticalSpace))).rotate(arrowAngle, shooterPosition), cos(arrowAngle), sin(arrowAngle));
		edgePosition.moveByVector(diagonalVector);
	}
	createBullet(MathPoint(edgePosition).rotate(arrowAngle, shooterPosition), cos(arrowAngle), sin(arrowAngle));
}

void Shootable::setViewingAngle(double newValue)
{
	viewingAngle = newValue;
}

Shootable::~Shootable()
{
	delete shootingTimer;
}
