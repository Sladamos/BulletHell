#include "MoveableObject.h"

MoveableObject::MoveableObject(std::string objectName, const Point& position, int radius) : 
	GameObject(objectName, position, radius), horizontalSpeed(0.0), verticalSpeed(0.0) {}
MoveableObject::MoveableObject(std::string objectName, const Point& position, const std::vector<Point>& corners) : 
	GameObject(objectName, position, corners), horizontalSpeed(0.0), verticalSpeed(0.0) {}

void MoveableObject::setHorizontalSpeed(double horizontalSpeed)
{
	this->horizontalSpeed = horizontalSpeed;
}

void MoveableObject::setVerticalSpeed(double verticalSpeed)
{
	this->verticalSpeed = verticalSpeed;
}

void MoveableObject::straightMove(double timeGain)
{
	position.moveByVector(horizontalSpeed * timeGain * Constants::horizontalSpeedMultiplier,
		verticalSpeed * timeGain * Constants::verticalSpeedMultiplier);
}