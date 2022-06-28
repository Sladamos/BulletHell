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
	if (position.getY() + objectPolygon->getMostTopCoordinate() < Constants::wallSize)
		position.setY((-1)*objectPolygon->getMostTopCoordinate() + Constants::wallSize);	//TODO: change
	else if (position.getY() + objectPolygon->getMostBottomCoordinate() > Constants::levelHeight - Constants::wallSize)
		position.setY(Constants::levelHeight - objectPolygon->getMostBottomCoordinate() - Constants::wallSize);

	if (position.getX() + objectPolygon->getMostLeftCoordinate() < Constants::wallSize)
		position.setX((-1)*objectPolygon->getMostLeftCoordinate() + Constants::wallSize);
	else if (position.getX() + objectPolygon->getMostRightCoordinate() > Constants::levelWidth - Constants::wallSize)
		position.setX(Constants::levelWidth - objectPolygon->getMostRightCoordinate() - Constants::wallSize);
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