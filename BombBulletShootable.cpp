#include "BombBulletShootable.h"
#include "Bomb.h"
#include "Level.h"

BombBulletShootable::BombBulletShootable(double shootingTimeLimit) : Shootable(shootingTimeLimit) {}

void BombBulletShootable::createBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed)
{
	if(rand() % 2 == 0)
		Level::addGameObject(new Bomb("./gfx/1stBomb", dynamic_cast<GameObject*>(this), position, horizontalSpeed * Bullet::speedMultiplier, verticalSpeed * Bullet::speedMultiplier));
	else
		Level::addGameObject(new Bomb("./gfx/2ndBomb", dynamic_cast<GameObject*>(this), position, horizontalSpeed * Bullet::speedMultiplier, verticalSpeed * Bullet::speedMultiplier));
}