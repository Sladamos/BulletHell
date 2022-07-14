#pragma once
#include "SpecialShootable.h"
class FireballShootable : public SpecialShootable
{
public:
	FireballShootable(double shootingTimeLimit);
private:
	void createSpecialBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed) override;
};

