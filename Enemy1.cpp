#include "Enemy1.h"

Enemy1::Enemy1(const std::string& objectName, const MathPoint& startingPoint, const std::vector<MathPoint>& corners) : 
	Enemy(objectName, startingPoint, corners, 0.1, 100) {}


void Enemy1::action(double timeGain)
{
	shootIfPossible(&Shootable::randomShooting);
}
