#include "UnholyCrumbleBullet.h"
#include "Level.h"

UnholyCrumbleBullet::UnholyCrumbleBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed) :
	UnholyBullet("./gfx/crumble", position, 20, 30, horizontalSpeed, verticalSpeed) {}

void UnholyCrumbleBullet::createBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed)
{
	Level::addGameObject(new UnholyBullet(position, horizontalSpeed * Bullet::speedMultiplier, verticalSpeed * Bullet::speedMultiplier));
}

UnholyCrumbleBullet::~UnholyCrumbleBullet()
{
	if(shouldBeDestroyed())
		shootIfPossible(&Shootable::circleShooting);
}