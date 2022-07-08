#include <vector>
#include "Enemy.h"
#include "Painter.h"
#include "BmpManager.h"
#include "Level.h"
#include "UnholyBullet.h"
using namespace std;

Enemy::Enemy(const string& objectName, const MathPoint& startingPoint, const vector<MathPoint>& corners, double shootingPeriod) :
	GameObject(objectName, MathPoint(startingPoint), corners, enemyMaxHealth), Shootable(shootingPeriod) {}

int Enemy::getHitpoints()
{
	return hitpoints;
}

bool Enemy::isInpenetrableBy(GameObject* gameObject)
{
	if (gameObject->isPlayer())
		return true;
	return false;
}

void Enemy::createBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed)
{
	Level::addBullet(new UnholyBullet(position, horizontalSpeed, verticalSpeed));
}

bool Enemy::isDamagableBy(GameObject* gameObject)
{
	if (gameObject->isHolyBullet())
		return true;
	return false;
}

