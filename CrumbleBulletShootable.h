#pragma once
#include "Shootable.h"
class CrumbleBulletShootable : public Shootable
{
public:
	CrumbleBulletShootable(double shootingTimeLimit);
private:
	void createBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed) override;
};

