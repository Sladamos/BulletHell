#pragma once
#include "Enemy.h"
#include "BombBulletShootable.h"
class Enemy4 : public Enemy, public BombBulletShootable
{
public:
	Enemy4(const std::string& objectName, const MathPoint& startingPoint, const std::vector<MathPoint>& corners);
	void action(double timeGain) override;
};

