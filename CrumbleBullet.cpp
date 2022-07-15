#include "CrumbleBullet.h"
#include "Level.h"

CrumbleBullet::CrumbleBullet(const MathPoint& position, GameObject* owner, double horizontalSpeed, double verticalSpeed) :
	Bullet("./gfx/crumble", owner, position, 20, 30, horizontalSpeed, verticalSpeed) {}

void CrumbleBullet::createBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed)
{
	if(getOwner()->isEnemy())
		Level::addGameObject(new Bullet("./gfx/unholyBullet", getOwner(), position, horizontalSpeed * Bullet::speedMultiplier, verticalSpeed * Bullet::speedMultiplier));
	else if (getOwner()->isPlayer())
		Level::addGameObject(new Bullet("./gfx/holyBullet", getOwner(), position, horizontalSpeed * Bullet::speedMultiplier, verticalSpeed * Bullet::speedMultiplier));
}

CrumbleBullet::~CrumbleBullet()
{
	if(shouldBeDestroyed())
		shootIfPossible(&Shootable::circleShooting);
}