#include "CrumbleBulletShootable.h"
#include "CrumbleBullet.h"
#include "Level.h"

CrumbleBulletShootable::CrumbleBulletShootable(double shootingTimeLimit) : Shootable(shootingTimeLimit) {}

void CrumbleBulletShootable::createBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed)
{
	Level::addGameObject(new CrumbleBullet(position, dynamic_cast<GameObject*>(this), horizontalSpeed * Bullet::speedMultiplier, verticalSpeed * Bullet::speedMultiplier));
}