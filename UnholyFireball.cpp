#include "UnholyFireball.h"

UnholyFireball::UnholyFireball(const MathPoint& position, double horizontalSpeed, double verticalSpeed) :
	UnholyBullet("./gfx/fireball", position, 30, 65, horizontalSpeed, verticalSpeed) {}