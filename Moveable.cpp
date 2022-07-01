#include "Moveable.h"
#include "Constants.h"

Moveable::Moveable() : horizontalSpeed(0.0), verticalSpeed(0.0) {}

void Moveable::setHorizontalSpeed(double horizontalSpeed)
{
	this->horizontalSpeed = horizontalSpeed;
}

void Moveable::setVerticalSpeed(double verticalSpeed)
{
	this->verticalSpeed = verticalSpeed;
}

void Moveable::straightMove(double timeGain, Point& position)
{
	position.moveByVector(horizontalSpeed * timeGain * Constants::horizontalSpeedMultiplier,
		verticalSpeed * timeGain * Constants::verticalSpeedMultiplier);
}