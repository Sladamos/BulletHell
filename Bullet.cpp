#include "Bullet.h"
#include "MathVector.h"
Bullet::Bullet(const std::string& objectName, const MathPoint& position, int damageDealt, double horizontalSpeed, double verticalSpeed) :
	GameObject(objectName, position, 13), Moveable(horizontalSpeed, verticalSpeed), damageDealt(damageDealt), launchPosition(position),
	toDestroy(false) {}

Bullet::Bullet(const std::string& objectName, const MathPoint& position, double horizontalSpeed, double verticalSpeed) 
	: Bullet(objectName, position, defaultDamage, horizontalSpeed, verticalSpeed) {}

void Bullet::action(double timeGain)
{
	move(timeGain, position);
	if (isOutOfRange())
		toDestroy = true;
}

bool Bullet::shouldBeDestroyed()
{
	return toDestroy;
}

bool Bullet::isOutOfRange()
{
	return MathVector(launchPosition, position).getLength() > maxRange;
}

void Bullet::repairMove(GameObject* collidableObject, double timeGain)
{
	toDestroy = true;
}

void Bullet::hit(GameObject* targetObject)
{
	targetObject->decreaseHitpoints(damageDealt);
	toDestroy = true;
}

