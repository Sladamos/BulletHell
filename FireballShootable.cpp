#include "FireballShootable.h"
#include "UnholyFireball.h"
#include "Level.h"

FireballShootable::FireballShootable(double shootingTimeLimit) : Shootable(shootingTimeLimit) {}

void FireballShootable::createBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed)
{
	Level::addGameObject(new UnholyFireball(position, horizontalSpeed * Bullet::speedMultiplier, verticalSpeed * Bullet::speedMultiplier));
}