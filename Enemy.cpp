#include <vector>
#include "Enemy.h"
#include "Painter.h"
#include "BmpManager.h"
#include "Level.h"
#include "Bullet.h"
using namespace std;

Enemy::Enemy(const string& objectName, const MathPoint& startingPoint, const vector<MathPoint>& corners, double shootingPeriod, int hitpoints) :
	GameObject(objectName, MathPoint(startingPoint), corners, hitpoints), Shootable(shootingPeriod) {}


bool Enemy::isInpenetrableBy(GameObject* gameObject)
{
	if (gameObject->isPlayer() || gameObject->isEnemy())
		return true;
	return false;
}

void Enemy::createBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed)
{
	Level::addGameObject(new Bullet("./gfx/unholyBullet", this, position, horizontalSpeed*Bullet::speedMultiplier, verticalSpeed*Bullet::speedMultiplier));
}

bool Enemy::doesGetDamagedBy(GameObject* gameObject)
{
	if (gameObject->isHolyBullet())
		return true;
	return false;
}

bool Enemy::shouldBeDestroyed()
{
	return hitpoints <= 0;
}

