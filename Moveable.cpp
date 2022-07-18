#include "Moveable.h"
#include "MathVector.h"
#include "GameObject.h"
#include "CollisionsChecker.h"

Moveable::Moveable(int numberOfFrames) : horizontalSpeed(0.0), verticalSpeed(0.0)
{
	animationTimer = new AnimationTimer(0.1 * numberOfFrames, numberOfFrames);
}

Moveable::Moveable(double horizontalSpeed, double verticalSpeed, double animationTime, int numberOfFrames) : horizontalSpeed(horizontalSpeed), verticalSpeed(verticalSpeed)
{
	animationTimer = new AnimationTimer(animationTime, numberOfFrames);
}

Moveable::Moveable(double horizontalSpeed, double verticalSpeed) : horizontalSpeed(horizontalSpeed), verticalSpeed(verticalSpeed), animationTimer(nullptr)
{}

int Moveable::getCurrentFrameNumber()
{
	if(horizontalSpeed == 0 && verticalSpeed == 0)
		animationTimer->resetTimer();
	return animationTimer->getCurrentFrameNumber();
}

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
	position.moveByVector(MathVector(MathPoint(-horizontalSpeed * timeGain * horizontalSpeedMultiplier, 0)));
}

void Moveable::undoVerticalMove(double timeGain, MathPoint& position)
{
	position.moveByVector(MathVector(MathPoint(0, -verticalSpeed * timeGain * verticalSpeedMultiplier)));
}

void Moveable::move(double timeGain, MathPoint& position)
{
	position.moveByVector(MathVector(MathPoint(horizontalSpeed * timeGain * horizontalSpeedMultiplier,
		verticalSpeed * timeGain * verticalSpeedMultiplier)));
}

void Moveable::repairMove(GameObject* collidableObject, double timeGain)
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

Moveable::~Moveable()
{
	if(animationTimer != nullptr)
		delete animationTimer;
}