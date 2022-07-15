#include "UnholyBullet.h"
#include "Player.h"

UnholyBullet::UnholyBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed) :
	Bullet("./gfx/unholyBullet", position, horizontalSpeed, verticalSpeed) {}

UnholyBullet::UnholyBullet(const std::string& objectName, const MathPoint& position, int damageDealt, int radius, double horizontalSpeed, double verticalSpeed) :
	Bullet(objectName, position, damageDealt, radius, horizontalSpeed, verticalSpeed) {}

void UnholyBullet::hit(GameObject* targetObject)
{
	Bullet::hit(targetObject);
	if (targetObject->isPlayer())
		dynamic_cast<Player*>(targetObject)->decreaseScore(10);
}