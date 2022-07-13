#include "MoveableEnemy.h"

MoveableEnemy::MoveableEnemy(const std::string& objectName, const MathPoint& startingPoint, const std::vector<MathPoint>& corners, double shootingPeriod, int hitpoints)
	: Enemy(objectName, startingPoint, corners, shootingPeriod, hitpoints), maximumSpeed(enemySpeedMultiplier), Moveable()
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

double MoveableEnemy::generateRandomSpeed()
{
	return rand() % 2 == 0 ? maximumSpeed : -maximumSpeed;
}

MoveableEnemy::~MoveableEnemy()
{
	delete speedChangingTimer;
}