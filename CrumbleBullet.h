#pragma once
#include "Bullet.h"
#include "Shootable.h"
class CrumbleBullet : public Bullet, public Shootable
{
public:
	CrumbleBullet(const MathPoint& position, GameObject* owner, double horizontalSpeed, double verticalSpeed);
	~CrumbleBullet();
private:
	void createBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed) override;
	bool isOwnedByEnemy;
};

