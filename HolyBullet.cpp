#include "HolyBullet.h"
HolyBullet::HolyBullet(const MathPoint& position, int radius, double horizontalSpeed, double verticalSpeed) : 
			Bullet("./gfx/holyBullet", position, radius, horizontalSpeed, verticalSpeed){}