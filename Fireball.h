#pragma once
#include "ExplosiveBullet.h"
class Fireball : public ExplosiveBullet
{
public:
	Fireball(const MathPoint& position, GameObject* owner, double horizontalSpeed, double verticalSpeed);
};

