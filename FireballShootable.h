#pragma once
#include "Shootable.h"
class FireballShootable : public Shootable
{
public:
	FireballShootable(double shootingTimeLimit);
private:
	void createBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed) override;
};

