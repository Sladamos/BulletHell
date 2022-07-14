#define _USE_MATH_DEFINES
#include <cmath>
#include "Shootable.h"
#include "HolyBullet.h"
#include "UnholyBullet.h"
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
	double randomAngle = rand() % 360 * M_PI / 180.00;
	int distanceFromShooter = 80;
	MathVector spaceVector = MathVector(MathPoint(distanceFromShooter + rand() % Bullet::maxRange, 0));
	createBullet(MathPoint(shooterPosition).moveByVector(spaceVector).rotate(randomAngle, shooterPosition), 0,0);
}

void Shootable::circleShooting()
{
	MathPoint position = dynamic_cast<GameObject*>(this)->getPosition();
	const int bulletsInCircle = 18, spaceSize = 4, spacePosition = rand() % (bulletsInCircle - spaceSize + 1);
	const double angleBetweenBullets = M_PI * 2 / bulletsInCircle;

	for (int i = 0; i < bulletsInCircle; i++)
		if (i < spacePosition || i >= spacePosition + spaceSize)
			createBullet(position, cos(angleBetweenBullets * i), sin(angleBetweenBullets * i));
}

void Shootable::randomShooting()
{
	double randomAngle = rand() % 360 * M_PI / 180.00;
	MathPoint position = dynamic_cast<GameObject*>(this)->getPosition();
	createBullet(position, cos(randomAngle), sin(randomAngle));
}

void Shootable::multipleShooting()
{
	const int numberOfBulletsInOneShoot = 5;
	const double angleBetweenBullets = 20 * M_PI / 180.00;
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
	const int numberOfLasers = 4;
	for (int i = 0; i < numberOfLasers; i++)
		createLaser();
}

void Shootable::createLaser()
{
	const int bulletsInLaser = 5, space = 30;
	double laserAngle = rand() % 360 * M_PI / 180.00;
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
	const int bulletsInArrow = 9, verticalSpace = 30, horizontalSpace = 15, distanceFromShooter = 30;	//number of bullets in an arrow has to be odd
	MathPoint shooterPosition = dynamic_cast<GameObject*>(this)->getPosition();
	MathPoint edgePosition = MathPoint(shooterPosition).moveByVector(MathVector(MathPoint(distanceFromShooter, -bulletsInArrow / 2 * verticalSpace)));
	MathVector diagonalVector = MathVector(MathPoint(horizontalSpace, verticalSpace));
	double arrowAngle = rand() % 360 * M_PI / 180.00;

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
