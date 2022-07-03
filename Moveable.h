#pragma once
#include "MathPoint.h"

class Moveable
{
public:
	Moveable();
	void setVerticalSpeed(double verticalSpeed);
	void setHorizontalSpeed(double horizontalSpeed);
	virtual void undoMove(double timeGain) = 0;
protected:
	void move(double timeGain, MathPoint& position);
	void undoMove(double timeGain, MathPoint& position);

	double horizontalSpeed, verticalSpeed;
};

