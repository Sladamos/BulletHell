#include "GameObject.h"
#include "BmpManager.h"
#include "ShapesManager.h"
#include "Painter.h"
#include "Camera.h"
#include "Moveable.h"
#include "Enemy.h"
#include "CollisionsChecker.h"
#include "HolyBullet.h"
#include "UnholyBullet.h"
using namespace std;

GameObject::GameObject(const string& objectName, const MathPoint& position, int radius) : objectName(objectName), position(position), hitpoints(0)
{
	BmpManager::loadStaticBitmap(objectName, radius);
}

GameObject::GameObject(const string& objectName, const MathPoint& position, const vector<MathPoint>& corners)
	: objectName(objectName), position(position), hitpoints(0)
{
	BmpManager::loadStaticBitmap(objectName, corners);
}

GameObject::GameObject(const string& objectName, const MathPoint& position, const vector<MathPoint>& corners, int hitpoints)
	: objectName(objectName), position(position), hitpoints(hitpoints)
{
	BmpManager::loadStaticBitmap(objectName, corners);
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

bool GameObject::isDamagableBy(GameObject* gameObject)
{
	return false;
}

bool GameObject::isPickableBy(GameObject* gameObject)
{
	return false;	//TODO: add pickable
}

void GameObject::action(double timeGain) {}

bool GameObject::isPlayer()
{
	return dynamic_cast<Player*>(this);
}

bool GameObject::isEnemy()
{
	return dynamic_cast<Enemy*>(this);
}

bool GameObject::isUnholyBullet()
{
	return dynamic_cast<UnholyBullet*>(this);
}

bool GameObject::isHolyBullet()
{
	return dynamic_cast<HolyBullet*>(this);
}


void GameObject::print(Painter* painter)
{
	painter->drawObject(BmpManager::getBitmap(objectName), Camera::getObjectPositionOnScreen(position));
}

void GameObject::checkCollisions(const std::list<GameObject*>& gameObjectsWithoutBullets, double timeGain)
{
	for (GameObject* collidableObject : gameObjectsWithoutBullets)
	{
		if (this != collidableObject && isMoveable() && CollisionsChecker::occursCollisionBetweenObjects(this, collidableObject))
		{
			if (collidableObject->isInpenetrableBy(this))
				dynamic_cast<Moveable*>(this)->repairMove(collidableObject, timeGain);
			else if (collidableObject->isDamagableBy(this))
				dynamic_cast<Bullet*>(this)->hit(collidableObject);
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
