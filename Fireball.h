#pragma once
#include "Bullet.h"
class Fireball : public Bullet
{
public:
	Fireball(const MathPoint& position, GameObject* owner, double horizontalSpeed, double verticalSpeed);
};

