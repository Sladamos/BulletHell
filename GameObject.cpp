#include "GameObject.h"
#include "BmpManager.h"
#include "Painter.h"
#include "MoveableObject.h"
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