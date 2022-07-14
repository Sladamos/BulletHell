#pragma once
#include "Bullet.h"
class UnholyBullet : public Bullet
{
public:
	UnholyBullet(const std::string& objectName, const MathPoint& position, int damageDealt, int radius, double horizontalSpeed, double verticalSpeed);
	UnholyBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed);
};

