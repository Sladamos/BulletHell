#pragma once
#include "Bullet.h"
class UnholyBullet : public Bullet
{
public:
	UnholyBullet(const MathPoint& position, int radius, double horizontalSpeed, double verticalSpeed);
};

