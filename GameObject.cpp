#include "GameObject.h"
#include "BmpManager.h"
#include "Painter.h"
using namespace std;

GameObject::GameObject(string objectName) : objectName(objectName), position(SCREEN_WIDTH/2,SCREEN_HEIGHT/2)
{
	BmpManager::loadStaticBitmap(objectName);
}

void GameObject::action(double timeGain)
{
}

void GameObject::print(Painter* painter)
{
	painter->drawObject(BmpManager::getBitmap(objectName), position);
}