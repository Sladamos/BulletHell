#pragma once
#include "MathPoint.h"

class Moveable
{
public:
	Moveable();
	void setVerticalSpeed(double verticalSpeed);
	void setHorizontalSpeed(double horizontalSpeed);
	virtual void undoVerticalMove(double timeGain) = 0;
	virtual void undoHorizontalMove(double timeGain) = 0;
protected:
	void move(double timeGain, MathPoint& position);
	void undoVerticalMove(double timeGain, MathPoint& position);
	void undoHorizontalMove(double timeGain, MathPoint& position);
	

	double horizontalSpeed, verticalSpeed;
};

