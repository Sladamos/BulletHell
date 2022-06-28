#pragma once
#include "GameObject.h"

class MoveableObject : public GameObject
{
public:
	MoveableObject(std::string objectName, const Point& position, int radius);
	MoveableObject(std::string objectName, const Point& position, const std::vector<Point>& corners);
	void setVerticalSpeed(double verticalSpeed);
	void setHorizontalSpeed(double horizontalSpeed);
protected:
	void basicMove(double timeGain);
	double horizontalSpeed, verticalSpeed;
};

