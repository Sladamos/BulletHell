#include "ExplosiveBullet.h"
#include "Level.h"
#include "Explosion.h"

ExplosiveBullet::ExplosiveBullet(const std::string& objectName, GameObject* owner, const MathPoint& position, int damageDealt, int radius, double horizontalSpeed, double verticalSpeed) :
	Bullet(objectName, owner, position, damageDealt, radius, horizontalSpeed, verticalSpeed) {}

ExplosiveBullet::~ExplosiveBullet()
{
	Level::addGameObject(new Explosion(getPosition()));
}