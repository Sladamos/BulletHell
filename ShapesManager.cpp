#include "ShapesManager.h"
using namespace std;

map<string, Shape*> ShapesManager::shapes = map<string, Shape*>();

void ShapesManager::addShape(const string& objectName, Shape* shape)
{
	if (shapes.find(objectName) == shapes.end())
		shapes.insert(pair <string, Shape*>(objectName, shape));
}

void ShapesManager::freeShapes()
{
	for (auto shape : shapes)
		delete shape.second;
	shapes.clear();
}

Shape* ShapesManager::getShape(const string& objectName)
{
	return shapes.find(objectName)->second;
}
