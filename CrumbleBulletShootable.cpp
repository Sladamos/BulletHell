#include "CrumbleBulletShootable.h"
#include "UnholyCrumbleBullet.h"
#include "Level.h"

CrumbleBulletShootable::CrumbleBulletShootable(double shootingTimeLimit) : Shootable(shootingTimeLimit) {}

void CrumbleBulletShootable::createBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed)
{
	Level::addGameObject(new UnholyCrumbleBullet(position, horizontalSpeed * Bullet::speedMultiplier, verticalSpeed * Bullet::speedMultiplier));
}