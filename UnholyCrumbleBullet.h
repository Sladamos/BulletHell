#pragma once
#include "UnholyBullet.h"
#include "Shootable.h"
class UnholyCrumbleBullet : public UnholyBullet, public Shootable
{
public:
	UnholyCrumbleBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed);
	~UnholyCrumbleBullet();
private:
	void createBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed) override;
};

