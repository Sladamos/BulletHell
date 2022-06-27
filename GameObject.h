#pragma once
#include <string>
#include "Point.h"
#include "Constants.h"
class Painter;
class GameObject
{
public:
	GameObject(std::string objectName, const Point& position);
	//GameObject(std::string objectName, int numberOfAnimations);	//TODO: add animations
	virtual void action(double timeGain);
	void print(Painter* painter);
protected:
	Point position;
	std::string objectName;
};

