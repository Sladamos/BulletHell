#pragma once
#include "HittingTimer.h"
#include "Bullet.h"
class Bomb : public Bullet
{
public:
	Bomb(const std::string& objectName, GameObject* owner, const MathPoint& position, double horizontalSpeed, double verticalSpeed);
	~Bomb();
	void hit(GameObject* targetObject) override;
	void action(double timeGain) override;
private:
	HittingTimer* hittingTimer;
};

