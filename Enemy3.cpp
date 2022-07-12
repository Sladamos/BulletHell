#include "Enemy3.h"

Enemy3::Enemy3(const std::string& objectName, const MathPoint& startingPoint, const std::vector<MathPoint>& corners) :
	MoveableEnemy(objectName, startingPoint, corners, 0.5, 450) {}

void Enemy3::action(double timeGain)
{
	MoveableEnemy::action(timeGain);
	shootIfPossible(&Shootable::arrowShooting);
}