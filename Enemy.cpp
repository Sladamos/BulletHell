#include <vector>
#include "Enemy.h"
#include "Painter.h"
#include "BmpManager.h"
using namespace std;

Enemy::Enemy(string objectName, const vector<MathPoint>& corners) : GameObject(objectName, MathPoint(200,200), corners), hitpoints(enemyMaxHealth) {}

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
	//TODO: implement shooting
}

