#pragma once
#include <string>
#include <vector>
#include "Point.h"
#include "Constants.h"
#include "Polygon.h"
class Painter;
class GameObject
{
public:
	GameObject(std::string objectName, const Point& position, int radius);
	GameObject(std::string objectName, const Point& position, const std::vector<Point>& corners);
	//GameObject(std::string objectName, int numberOfAnimations);	//TODO: add animations
	virtual void checkLevelBorderCollision();
	virtual void action(double timeGain);
	virtual void print(Painter* painter);
	bool isMoveable();
	Point getPosition();
protected:
	Point position;
	std::string objectName;
private:
	bool isTryingToCrossTopBorder(Polygon* objectPolygon);
	bool isTryingToCrossRightBorder(Polygon* objectPolygon);
	bool isTryingToCrossBottomBorder(Polygon* objectPolygon);
	bool isTryingToCrossLeftBorder(Polygon* objectPolygon);
};

