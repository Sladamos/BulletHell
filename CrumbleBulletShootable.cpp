#include "CrumbleBulletShootable.h"
#include "UnholyCrumbleBullet.h"
#include "Level.h"

CrumbleBulletShootable::CrumbleBulletShootable(double shootingTimeLimit) : SpecialShootable(shootingTimeLimit) {}

void CrumbleBulletShootable::createSpecialBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed)
{
	Level::addGameObject(new UnholyCrumbleBullet(position, horizontalSpeed * Bullet::speedMultiplier, verticalSpeed * Bullet::speedMultiplier));
}