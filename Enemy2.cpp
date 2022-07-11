#include "Enemy2.h"

Enemy2::Enemy2(const std::string& objectName, const MathPoint& startingPoint, const std::vector<MathPoint>& corners) :
	Enemy(objectName, startingPoint, corners, 0.4, 200) {}


void Enemy2::action(double timeGain)
{
	shootIfPossible(&Shootable::laserShooting);
}
