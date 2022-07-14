#pragma once
#include "HittingTimer.h"
#include "UnholyBullet.h"
class UnholyBomb : public UnholyBullet
{
public:
	UnholyBomb(const std::string& objectName, const MathPoint& position, double horizontalSpeed, double verticalSpeed);
	~UnholyBomb();
	void hit(GameObject* targetObject) override;
	void action(double timeGain) override;
private:
	HittingTimer* hittingTimer;
};

