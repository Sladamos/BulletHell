#include "FireballShootable.h"
#include "Fireball.h"
#include "Level.h"

FireballShootable::FireballShootable(double shootingTimeLimit) : Shootable(shootingTimeLimit) {}

void FireballShootable::createBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed)
{
	Level::addGameObject(new Fireball(position, dynamic_cast<GameObject*>(this), horizontalSpeed * Bullet::speedMultiplier, verticalSpeed * Bullet::speedMultiplier));
}