#include "BombBulletShootable.h"
#include "UnholyBomb.h"
#include "Level.h"

BombBulletShootable::BombBulletShootable(double shootingTimeLimit) : Shootable(shootingTimeLimit) {}

void BombBulletShootable::createBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed)
{
	if(rand() % 2 == 0)
		Level::addGameObject(new UnholyBomb("./gfx/1stBomb",position, horizontalSpeed * Bullet::speedMultiplier, verticalSpeed * Bullet::speedMultiplier));
	else
		Level::addGameObject(new UnholyBomb("./gfx/2ndBomb",position, horizontalSpeed * Bullet::speedMultiplier, verticalSpeed * Bullet::speedMultiplier));
}