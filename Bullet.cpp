#include "Bullet.h"
#include "MathVector.h"
Bullet::Bullet(std::string objectName, const MathPoint& position, int damageDealt, int radius) :
	GameObject(objectName, position, radius), Moveable(), damageDealt(damageDealt), launchPosition(position), currentDistance(0) {}

void Bullet::action(double timeGain)
{
	move(timeGain, position);
	currentDistance = MathVector(position, launchPosition).getLength();
}

bool Bullet::shouldBeDestroyed()
{
	if (currentDistance > maxRange)
		return true;
	return false;
}
