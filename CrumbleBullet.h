#pragma once
#include "ExplosiveBullet.h"
#include "Shootable.h"
class CrumbleBullet : public ExplosiveBullet, public Shootable
{
public:
	CrumbleBullet(const MathPoint& position, GameObject* owner, double horizontalSpeed, double verticalSpeed);
	~CrumbleBullet();
private:
	void createBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed) override;
	bool isOwnedByEnemy;
};

