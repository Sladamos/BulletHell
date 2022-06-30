#pragma once
#include <string>
#include <vector>
#include "Point.h"
#include "Constants.h"
#include "Shape.h"
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
	bool isTryingToCrossTopBorder(Shape* objectShape);
	bool isTryingToCrossRightBorder(Shape* objectShape);
	bool isTryingToCrossBottomBorder(Shape* objectShape);
	bool isTryingToCrossLeftBorder(Shape* objectShape);
};

