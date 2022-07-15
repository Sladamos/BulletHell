#pragma once
#include "Bullet.h"
class HolyBullet : public Bullet
{
public:
	HolyBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed);
	void hit(GameObject* targetObject) override;
};

