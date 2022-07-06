#include <cmath>
#include "Shootable.h"
#include "TimeManager.h"
#include "Level.h"
#include "Bullet.h"

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
	//TODO: holy/unholy?
	double angle = rand() % 360 * M_PI / 180.00;
	MathPoint position = dynamic_cast<GameObject*>(this)->getPosition();
	Level::addBullet(new Bullet("./gfx/holyBullet", position, 13, cos(angle)*2, sin(angle)*2));
}

Shootable::~Shootable()
{
	delete shootingTimer;
}