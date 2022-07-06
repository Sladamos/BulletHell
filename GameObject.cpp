#include "GameObject.h"
#include "BmpManager.h"
#include "ShapesManager.h"
#include "Painter.h"
#include "Camera.h"
#include "Moveable.h"
#include "Enemy.h"
using namespace std;

GameObject::GameObject(const string& objectName, const MathPoint& position, int radius) : objectName(objectName), position(position)
{
	BmpManager::loadStaticBitmap(objectName, radius);
}

GameObject::GameObject(const string& objectName, const MathPoint& position, const vector<MathPoint>& corners)
	: objectName(objectName), position(position)
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

void GameObject::print(Painter* painter)
{
	painter->drawObject(BmpManager::getBitmap(objectName), Camera::getObjectPositionOnScreen(position));
}

bool GameObject::shouldBeDestroyed()
{
	return false;
}