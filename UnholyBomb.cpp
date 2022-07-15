#include "UnholyBomb.h"

UnholyBomb::UnholyBomb(const std::string& objectName, const MathPoint& position, double horizontalSpeed, double verticalSpeed) : 
	UnholyBullet(objectName, position, 25, 60, horizontalSpeed, verticalSpeed)
{
	hittingTimer = new HittingTimer(1.25);
}

void UnholyBomb::action(double timeGain)
{
	Bullet::action(timeGain);
	if (hittingTimer->isPermissionToHit())
		toDestroy = true;
}

void UnholyBomb::hit(GameObject* targetObject)
{
	if (hittingTimer->isPermissionToHit())
		UnholyBullet::hit(targetObject);
}

UnholyBomb::~UnholyBomb()
{
	delete hittingTimer;
}