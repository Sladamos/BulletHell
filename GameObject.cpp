#include "GameObject.h"
#include "BmpManager.h"
#include "PolygonsManager.h"
#include "Painter.h"
#include "MoveableObject.h"
using namespace std;

GameObject::GameObject(string objectName, const Point& position, int radius) : objectName(objectName), position(position)
{
	BmpManager::loadStaticBitmap(objectName, radius);
}

void GameObject::checkLevelBorderCollision()
{
	Polygon* objectPolygon = PolygonsManager::getPolygon(objectName);
	if (position.getY() + objectPolygon->getMostTopCoordinate() < 0)
		position.setY((-1)*objectPolygon->getMostTopCoordinate());	//TODO: change
	else if (position.getY() + objectPolygon->getMostBottomCoordinate() > Constants::levelHeight)
		position.setY(Constants::levelHeight - objectPolygon->getMostBottomCoordinate());

	if (position.getX() + objectPolygon->getMostLeftCoordinate() < 0)
		position.setX((-1)*objectPolygon->getMostLeftCoordinate());
	else if (position.getX() + objectPolygon->getMostRightCoordinate() > Constants::levelWidth)
		position.setX(Constants::levelWidth - objectPolygon->getMostRightCoordinate());
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

void GameObject::print(Painter* painter)
{
	painter->drawObject(BmpManager::getBitmap(objectName), position);
}