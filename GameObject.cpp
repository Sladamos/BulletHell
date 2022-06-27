#include "GameObject.h"
#include "BmpManager.h"
#include "Painter.h"
using namespace std;

GameObject::GameObject(string objectName, const Point& position) : objectName(objectName), position(position)
{
	BmpManager::loadStaticBitmap(objectName);
}

void GameObject::action(double timeGain)
{}

void GameObject::print(Painter* painter)
{
	painter->drawObject(BmpManager::getBitmap(objectName), position);
}