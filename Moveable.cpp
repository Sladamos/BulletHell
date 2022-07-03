#include "Moveable.h"
#include "Constants.h"
#include "MathVector.h"

Moveable::Moveable() : horizontalSpeed(0.0), verticalSpeed(0.0) {}

void Moveable::setHorizontalSpeed(double horizontalSpeed)
{
	this->horizontalSpeed = horizontalSpeed;
}

void Moveable::setVerticalSpeed(double verticalSpeed)
{
	this->verticalSpeed = verticalSpeed;
}

void Moveable::undoMove(double timeGain, MathPoint& position)
{
	position.moveByVector(MathVector(MathPoint(-horizontalSpeed * timeGain * Constants::horizontalSpeedMultiplier,
			-verticalSpeed * timeGain * Constants::verticalSpeedMultiplier)));
}

void Moveable::move(double timeGain, MathPoint& position)
{
	position.moveByVector(MathVector(MathPoint(horizontalSpeed * timeGain * Constants::horizontalSpeedMultiplier,
		verticalSpeed * timeGain * Constants::verticalSpeedMultiplier)));
}