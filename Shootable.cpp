#include "Shootable.h"
#include "TimeManager.h"

Shootable::Shootable(double shootingTimeLimit)
{
	shootingTimer = new ShootingTimer(0.5);
	TimeManager::addTimer(shootingTimer);
}

void Shootable::shootIfPossible(void(Shootable::*shootingPattern)())
{
	if (shootingTimer->isPermissionToShoot())
	{
		shootingPattern();
		shootingTimer->resetTimer();
	}
}

void Shootable::randomShooting()
{

}

Shootable::~Shootable()
{
	delete shootingTimer;
}