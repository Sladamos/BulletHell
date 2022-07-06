#include "Moveable.h"
#include "Constants.h"
#include "MathVector.h"
#include "GameObject.h"
#include "CollisionsChecker.h"

Moveable::Moveable() : horizontalSpeed(0.0), verticalSpeed(0.0) {}

Moveable::Moveable(double horizontalSpeed, double verticalSpeed) : horizontalSpeed(horizontalSpeed), verticalSpeed(verticalSpeed) {}

void Moveable::setHorizontalSpeed(double horizontalSpeed)
{
	this->horizontalSpeed = horizontalSpeed;
}

void Moveable::setVerticalSpeed(double verticalSpeed)
{
	this->verticalSpeed = verticalSpeed;
}

void Moveable::undoHorizontalMove(double timeGain, MathPoint& position)
{
	position.moveByVector(MathVector(MathPoint(-horizontalSpeed * timeGain * Constants::horizontalSpeedMultiplier, 0)));
}

void Moveable::undoVerticalMove(double timeGain, MathPoint& position)
{
	position.moveByVector(MathVector(MathPoint(0, -verticalSpeed * timeGain * Constants::verticalSpeedMultiplier)));
}

void Moveable::move(double timeGain, MathPoint& position)
{
	position.moveByVector(MathVector(MathPoint(horizontalSpeed * timeGain * Constants::horizontalSpeedMultiplier,
		verticalSpeed * timeGain * Constants::verticalSpeedMultiplier)));
}

void Moveable::repairMove(GameObject*& collidableObject, double timeGain)
{
	GameObject* repairingObject = dynamic_cast<GameObject*>(this);
	MathPoint incorretPosition = repairingObject->getPosition();
	undoHorizontalMove(timeGain);
	if (CollisionsChecker::occursCollisionBetweenObjects(repairingObject, collidableObject))
	{
		repairingObject->setPosition(incorretPosition);
		undoVerticalMove(timeGain);
	}
}