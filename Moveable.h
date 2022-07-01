#pragma once
#include "Point.h"

class Moveable
{
public:
	Moveable();
	void setVerticalSpeed(double verticalSpeed);
	void setHorizontalSpeed(double horizontalSpeed);
protected:
	void straightMove(double timeGain, Point& position);

	double horizontalSpeed, verticalSpeed;
};

