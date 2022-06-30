#pragma once
#include <map>
#include <string>
#include <vector>
#include "Shape.h"
class ShapesManager
{
public:
	static void addShape(const std::string& objectName, Shape* shape);
	static Shape* getShape(const std::string& objectName);
	static void freeShapes();
private:
	static std::map<std::string, Shape*> shapes;
};

