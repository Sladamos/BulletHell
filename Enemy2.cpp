#include "Enemy2.h"

Enemy2::Enemy2(const std::string& objectName, const MathPoint& startingPoint, const std::vector<MathPoint>& corners) :
	Enemy(objectName, startingPoint, corners, 0.4, 200), CrumbleBulletShootable(2) {}


void Enemy2::action(double timeGain)
{
	Shootable::shootIfPossible(&Shootable::circleShooting);
	CrumbleBulletShootable::shootIfPossible(&Shootable::randomShooting);
}
