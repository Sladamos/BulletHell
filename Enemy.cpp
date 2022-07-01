#include <vector>
#include "Enemy.h"
#include "Painter.h"
#include "BmpManager.h"
using namespace std;

Enemy::Enemy(string objectName, const vector<Point>& corners) : GameObject(objectName, Point(200,200), corners), hitpoints(enemyMaxHealth) {}

int Enemy::getHitpoints()
{
	return hitpoints;
}

void Enemy::action(double timeGain)
{
	//TODO: implement shooting
}

