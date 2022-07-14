#pragma once
#include "SpecialShootable.h"
class CrumbleBulletShootable : public SpecialShootable
{
public:
	CrumbleBulletShootable(double shootingTimeLimit);
private:
	void createSpecialBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed) override;
};

