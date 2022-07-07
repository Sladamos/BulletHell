#pragma once
#include "Bullet.h"
class HolyBullet : public Bullet
{
public:
	HolyBullet(const MathPoint& position, int radius, double horizontalSpeed, double verticalSpeed);
};

