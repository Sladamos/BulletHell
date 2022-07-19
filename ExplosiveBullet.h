#pragma once
#include "Bullet.h"
class ExplosiveBullet : public Bullet
{
public:
	ExplosiveBullet(const std::string& objectName, GameObject* owner, const MathPoint& position, int damageDealt, int radius, double horizontalSpeed, double verticalSpeed);
	virtual ~ExplosiveBullet();
};

