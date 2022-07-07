#include <vector>
#include "Enemy.h"
#include "Painter.h"
#include "BmpManager.h"
#include "Level.h"
#include "UnholyBullet.h"
using namespace std;

Enemy::Enemy(const string& objectName, const vector<MathPoint>& corners) : GameObject(objectName, MathPoint(200, 200), corners, enemyMaxHealth),
				Shootable(0.2) {}	//TODO: move time limit to enemy constructor

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

void Enemy::action(double timeGain)
{
	shootIfPossible(&Shootable::randomShooting);
}

void Enemy::createBullet(const MathPoint& position, int radius, double horizontalSpeed, double verticalSpeed)
{
	Level::addBullet(new UnholyBullet(position, radius, horizontalSpeed, verticalSpeed));
}

bool Enemy::isDamagableBy(GameObject* gameObject)
{
	if (gameObject->isHolyBullet())
		return true;
	return false;
}

