#include "MoveableEnemy.h"
#include "Painter.h"
#include "BmpManager.h"
#include "Camera.h"

MoveableEnemy::MoveableEnemy(const std::string& objectName, int numberOfFrames, const MathPoint& startingPoint, const std::vector<MathPoint>& corners, double shootingPeriod, int hitpoints)
	: Enemy(objectName, numberOfFrames, startingPoint, corners, shootingPeriod, hitpoints), maximumSpeed(enemySpeedMultiplier), Moveable(numberOfFrames)
{
	Moveable::setHorizontalSpeed(generateRandomSpeed());
	Moveable::setVerticalSpeed(generateRandomSpeed());
	speedChangingTimer = new ChangesTimer(0.75);
}

void MoveableEnemy::undoHorizontalMove(double timeGain)
{
	Moveable::undoHorizontalMove(timeGain, position);
	Moveable::setHorizontalSpeed(-horizontalSpeed);
}

void MoveableEnemy::undoVerticalMove(double timeGain)
{
	Moveable::undoVerticalMove(timeGain, position);
	Moveable::setVerticalSpeed(-verticalSpeed);
}

void MoveableEnemy::action(double timeGain)
{
	if (speedChangingTimer->isPermissionToChange())
	{
		Moveable::setVerticalSpeed(generateRandomSpeed());
		Moveable::setHorizontalSpeed(generateRandomSpeed());
		speedChangingTimer->resetTimer();
	}
	move(timeGain, position);
}

void MoveableEnemy::print(Painter* painter)
{
	painter->drawObject(BmpManager::getAnimation(objectName, getCurrentFrameNumber()), Camera::getObjectPositionOnScreen(position));
}


double MoveableEnemy::generateRandomSpeed()
{
	return (rand() % 3 - 1) * maximumSpeed;
}

MoveableEnemy::~MoveableEnemy()
{
	delete speedChangingTimer;
}