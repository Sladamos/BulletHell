#include "Bullet.h"
#include "Player.h"
#include "Level.h"
#include "MathVector.h"

Bullet::Bullet(const std::string& objectName, GameObject* owner, const MathPoint& position, int damageDealt, int radius, double horizontalSpeed, double verticalSpeed) :
	GameObject(objectName, position, radius), Moveable(horizontalSpeed, verticalSpeed), damageDealt(damageDealt), launchPosition(position),
	toDestroy(false), owner(owner) {}

Bullet::Bullet(const std::string& objectName, GameObject* owner, const MathPoint& position, int damageDealt, double horizontalSpeed, double verticalSpeed) :
	Bullet(objectName, owner, position, damageDealt, 13, horizontalSpeed, verticalSpeed) {}

Bullet::Bullet(const std::string& objectName, GameObject* owner, const MathPoint& position, double horizontalSpeed, double verticalSpeed)
	: Bullet(objectName, owner, position, defaultDamage, horizontalSpeed, verticalSpeed) {}

GameObject* Bullet::getOwner()
{
	return owner;
}

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
	changeScoreIfNecessary(targetObject);
	toDestroy = true;
}

void Bullet::changeScoreIfNecessary(GameObject* targetObject)
{
	if (targetObject->isPlayer())
		dynamic_cast<Player*>(targetObject)->decreaseScore(10);
	else if (targetObject->isEnemy() && getOwner()->isPlayer())
		dynamic_cast<Player*>(getOwner())->increaseScore(15);
}
