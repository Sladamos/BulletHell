#include "Fireball.h"

Fireball::Fireball(const MathPoint& position, GameObject* owner, double horizontalSpeed, double verticalSpeed) :
	ExplosiveBullet("./gfx/fireball", owner, position, 30, 65, horizontalSpeed, verticalSpeed) {}