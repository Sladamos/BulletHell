#include "GameObject.h"
#include "BmpManager.h"
#include "ShapesManager.h"
#include "Painter.h"
#include "Camera.h"
#include "Moveable.h"
using namespace std;

GameObject::GameObject(string objectName, const Point& position, int radius) : objectName(objectName), position(position)
{
	BmpManager::loadStaticBitmap(objectName, radius);
}

GameObject::GameObject(string objectName, const Point& position, const vector<Point>& corners)
	: objectName(objectName), position(position)
{
	BmpManager::loadStaticBitmap(objectName, corners);
}

Point GameObject::getPosition()
{
	return position;
}

void GameObject::checkLevelBorderCollision()
{
	Shape* objectShape = ShapesManager::getShape(objectName);
	if (isTryingToCrossTopBorder(objectShape))
		position.setY((-1)*objectShape->getMostTopCoordinate() + Constants::wallSize);
	else if (isTryingToCrossBottomBorder(objectShape))
		position.setY(Constants::levelHeight - objectShape->getMostBottomCoordinate() - Constants::wallSize);

	if (isTryingToCrossRightBorder(objectShape))
		position.setX(Constants::levelWidth - objectShape->getMostRightCoordinate() - Constants::wallSize);
	else if (isTryingToCrossLeftBorder(objectShape))
		position.setX((-1)*objectShape->getMostLeftCoordinate() + Constants::wallSize);
}

bool GameObject::isMoveable()
{
	if(dynamic_cast<Moveable*>(this) != nullptr)
		return true;
	return false;
}

void GameObject::action(double timeGain)
{}

bool GameObject::isTryingToCrossTopBorder(Shape* objectShape)
{
	return position.getY() + objectShape->getMostTopCoordinate() < Constants::wallSize;
}

bool GameObject::isTryingToCrossRightBorder(Shape* objectShape)
{
	return position.getX() + objectShape->getMostRightCoordinate() > Constants::levelWidth - Constants::wallSize;
}

bool GameObject::isTryingToCrossBottomBorder(Shape* objectShape)
{
	return position.getY() + objectShape->getMostBottomCoordinate() > Constants::levelHeight - Constants::wallSize;
}

bool GameObject::isTryingToCrossLeftBorder(Shape* objectShape)
{
	return position.getX() + objectShape->getMostLeftCoordinate() < Constants::wallSize;
}

void GameObject::print(Painter* painter)
{
	painter->drawObject(BmpManager::getBitmap(objectName), Camera::getObjectPositionOnScreen(position));
}