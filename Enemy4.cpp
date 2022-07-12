#include "Enemy4.h"

Enemy4::Enemy4(const std::string& objectName, const MathPoint& startingPoint, const std::vector<MathPoint>& corners) :
	Enemy(objectName, startingPoint, corners, 0.4, 850) {}

void Enemy4::action(double timeGain)
{
	shootIfPossible(&Shootable::laserShooting);
}