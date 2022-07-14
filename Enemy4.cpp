#include "Enemy4.h"

Enemy4::Enemy4(const std::string& objectName, const MathPoint& startingPoint, const std::vector<MathPoint>& corners) :
	Enemy(objectName, startingPoint, corners, 0.45, 650), BombBulletShootable(0.75) {}

void Enemy4::action(double timeGain)
{
	Shootable::shootIfPossible(&Shootable::laserShooting);
	BombBulletShootable::shootIfPossible(&Shootable::placeBullet);
}