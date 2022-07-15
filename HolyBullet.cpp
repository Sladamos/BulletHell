#include "HolyBullet.h"
#include "Level.h"

HolyBullet::HolyBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed) : 
			Bullet("./gfx/holyBullet", position, horizontalSpeed, verticalSpeed){}

void HolyBullet::hit(GameObject* targetObject)
{
	Bullet::hit(targetObject);
	if (targetObject->isEnemy())
		Level::getPlayer()->increaseScore(15);
}