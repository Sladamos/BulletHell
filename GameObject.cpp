#include "GameObject.h"
#include "BmpManager.h"
#include "PolygonsManager.h"
#include "Painter.h"
#include "Camera.h"
#include "MoveableObject.h"
using namespace std;

GameObject::GameObject(string objectName, const Point& position, int radius) : objectName(objectName), position(position)
{
	BmpManager::loadStaticBitmap(objectName, radius);
}

Point GameObject::getPosition()
{
	return position;
}

void GameObject::checkLevelBorderCollision()
{
	Polygon* objectPolygon = PolygonsManager::getPolygon(objectName);
	if (isTryingToCrossTopBorder(objectPolygon))
		position.setY((-1)*objectPolygon->getMostTopCoordinate() + Constants::wallSize);
	else if (isTryingToCrossBottomBorder(objectPolygon))
		position.setY(Constants::levelHeight - objectPolygon->getMostBottomCoordinate() - Constants::wallSize);

	if (isTryingToCrossRightBorder(objectPolygon))
		position.setX(Constants::levelWidth - objectPolygon->getMostRightCoordinate() - Constants::wallSize);
	else if (isTryingToCrossLeftBorder(objectPolygon))
		position.setX((-1)*objectPolygon->getMostLeftCoordinate() + Constants::wallSize);
}

GameObject::GameObject(string objectName, const Point& position, const vector<Point>& corners) 
	: objectName(objectName), position(position)
{
	BmpManager::loadStaticBitmap(objectName, corners);
}

bool GameObject::isMoveable()
{
	if(dynamic_cast<MoveableObject*>(this) != nullptr)
		return true;
	return false;
}

void GameObject::action(double timeGain)
{}

bool GameObject::isTryingToCrossTopBorder(Polygon* objectPolygon)
{
	return position.getY() + objectPolygon->getMostTopCoordinate() < Constants::wallSize;
}

bool GameObject::isTryingToCrossRightBorder(Polygon* objectPolygon)
{
	return position.getX() + objectPolygon->getMostRightCoordinate() > Constants::levelWidth - Constants::wallSize;
}

bool GameObject::isTryingToCrossBottomBorder(Polygon* objectPolygon)
{
	return position.getY() + objectPolygon->getMostBottomCoordinate() > Constants::levelHeight - Constants::wallSize;
}

bool GameObject::isTryingToCrossLeftBorder(Polygon* objectPolygon)
{
	return position.getX() + objectPolygon->getMostLeftCoordinate() < Constants::wallSize;
}

void GameObject::print(Painter* painter)
{
	painter->drawObject(BmpManager::getBitmap(objectName), Camera::getObjectPositionOnScreen(position));
}