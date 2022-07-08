#include "UnholyBullet.h"
UnholyBullet::UnholyBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed) :
	Bullet("./gfx/unholyBullet", position, horizontalSpeed, verticalSpeed) {}