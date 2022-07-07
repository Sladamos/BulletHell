#include "UnholyBullet.h"
UnholyBullet::UnholyBullet(const MathPoint& position, int radius, double horizontalSpeed, double verticalSpeed) :
	Bullet("./gfx/unholyBullet", position, radius, horizontalSpeed, verticalSpeed) {}