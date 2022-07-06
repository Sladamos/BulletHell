#include "Bullet.h"
#include "MathVector.h"
Bullet::Bullet(std::string objectName, const MathPoint& position, int damageDealt, int radius) :
	GameObject(objectName, position, radius), Moveable(), damageDealt(damageDealt), launchPosition(position), toDestroy(false) {}

Bullet::Bullet(std::string objectName, const MathPoint& position, int radius) : Bullet(objectName, position, defaultDamage, radius) {}

void Bullet::action(double timeGain)
{
	move(timeGain, position);
	if (isOutOfRange())
		toDestroy = true;
	//TODO: -> repair object move trzeba zmieniæ to na metodê gameobjectov¹ virtualn¹
}

bool Bullet::shouldBeDestroyed()
{
	return toDestroy;
}

bool Bullet::isOutOfRange()
{
	return MathVector(launchPosition, position).getLength() > maxRange;
}

