#pragma once
#include "Shootable.h"
class BombBulletShootable : public Shootable
{
public:
	BombBulletShootable(double shootingTimeLimit);
private:
	void createBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed) override;
};

