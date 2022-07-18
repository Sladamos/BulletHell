#include "GameObject.h"
#include "BmpManager.h"
#include "ShapesManager.h"
#include "Painter.h"
#include "Camera.h"
#include "Moveable.h"
#include "Enemy.h"
#include "CollisionsChecker.h"
#include "Bullet.h"
#include "Pickable.h"
using namespace std;

GameObject::GameObject(const string& objectName, const MathPoint& position, int radius) : objectName(objectName), position(position), hitpoints(0), maxHealth(0)
{
	BmpManager::loadStaticBitmap(objectName, radius);
}

GameObject::GameObject(const string& objectName, const MathPoint& position, const vector<MathPoint>& corners)
	: objectName(objectName), position(position), hitpoints(0), maxHealth(0)
{
	BmpManager::loadStaticBitmap(objectName, corners);
}

GameObject::GameObject(const string& objectName, const MathPoint& position, const vector<MathPoint>& corners, int hitpoints)
	: objectName(objectName), position(position), hitpoints(hitpoints), maxHealth(hitpoints)
{
	BmpManager::loadStaticBitmap(objectName, corners);
}

GameObject::GameObject(const std::string& objectName, const MathPoint& position, int radius, int numberOfFrames) : objectName(objectName), position(position), hitpoints(0), maxHealth(0)
{
	BmpManager::loadAnimation(objectName, radius, numberOfFrames);
}

GameObject::GameObject(const std::string& objectName, const MathPoint& position, const std::vector<MathPoint>& corners, int hitpoints, int numberOfFrames)
	: objectName(objectName), position(position), hitpoints(hitpoints), maxHealth(hitpoints)
{
	BmpManager::loadAnimation(objectName, corners, numberOfFrames);
}

int GameObject::getMaxHitpoints()
{
	return maxHealth;
}

int GameObject::getHitpoints()
{
	return hitpoints;
}

void GameObject::setPosition(const MathPoint& position)
{
	this->position = position;
}

Shape* GameObject::getShape()
{
	return ShapesManager::getShape(objectName);
}

MathPoint GameObject::getPosition()
{
	return position;
}

bool GameObject::isMoveable()
{
	if(dynamic_cast<Moveable*>(this) != nullptr)
		return true;
	return false;
}

bool GameObject::isInpenetrableBy(GameObject* gameObject)
{
	return false;
}

bool GameObject::doesGetDamagedBy(GameObject* gameObject)
{
	return false;
}

bool GameObject::isPickableBy(GameObject* gameObject)
{
	return false;
}

void GameObject::action(double timeGain) {}

bool GameObject::isPlayer()
{
	return dynamic_cast<Player*>(this);
}

bool GameObject::isBullet()
{
	return dynamic_cast<Bullet*>(this);
}

bool GameObject::isEnemy()
{
	return dynamic_cast<Enemy*>(this);
}

bool GameObject::isUnholyBullet()
{
	return isBullet() && dynamic_cast<Bullet*>(this)->getOwner()->isEnemy();
}

bool GameObject::isHolyBullet()
{
	return isBullet() && dynamic_cast<Bullet*>(this)->getOwner()->isPlayer();
}

void GameObject::print(Painter* painter)
{
	painter->drawObject(BmpManager::getBitmap(objectName), Camera::getObjectPositionOnScreen(position));
}

void GameObject::checkCollisions(const std::list<GameObject*>& gameObjectsWithoutBullets, double timeGain)
{
	for (GameObject* collidableObject : gameObjectsWithoutBullets)
	{
		if (this != collidableObject && !collidableObject->shouldBeDestroyed() && isMoveable() && CollisionsChecker::occursCollisionBetweenObjects(this, collidableObject))
		{
			if (collidableObject->isInpenetrableBy(this))
				dynamic_cast<Moveable*>(this)->repairMove(collidableObject, timeGain);
			else if (collidableObject->doesGetDamagedBy(this))
				dynamic_cast<Bullet*>(this)->hit(collidableObject);
			else if (collidableObject->isPickableBy(this))
				dynamic_cast<Pickable*>(collidableObject)->affectOn(this);
		}
	}
}

bool GameObject::shouldBeDestroyed()
{
	return false;
}

void GameObject::decreaseHitpoints(int damageDealt)
{
	hitpoints -= damageDealt;
}

void GameObject::increaseHitpoints(int healValue)
{
	hitpoints = hitpoints + healValue < maxHealth ? hitpoints + healValue : maxHealth;
}
