#include "Bomb.h"

Bomb::Bomb(const std::string& objectName, GameObject* owner, const MathPoint& position, double horizontalSpeed, double verticalSpeed) :
	ExplosiveBullet(objectName, owner, position, 25, 60, horizontalSpeed, verticalSpeed)
{
	hittingTimer = new HittingTimer(1.25);
}

void Bomb::action(double timeGain)
{
	Bullet::action(timeGain);
	if (hittingTimer->isPermissionToHit())
		toDestroy = true;
}

void Bomb::hit(GameObject* targetObject)
{
	if (hittingTimer->isPermissionToHit())
		Bullet::hit(targetObject);
}

Bomb::~Bomb()
{
	delete hittingTimer;
}