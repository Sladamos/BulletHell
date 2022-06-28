#pragma once
#include <string>
#include <vector>
#include "Point.h"
#include "Constants.h"
class Painter;
class GameObject
{
public:
	GameObject(std::string objectName, const Point& position, int radius);
	GameObject(std::string objectName, const Point& position, const std::vector<Point>& corners);
	//GameObject(std::string objectName, int numberOfAnimations);	//TODO: add animations
	virtual void checkLevelBorderCollision();
	bool isMoveable();
	virtual void action(double timeGain);
	void print(Painter* painter);
protected:
	Point position;
	std::string objectName;
};

