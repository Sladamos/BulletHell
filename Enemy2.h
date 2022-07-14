#pragma once
#include <string>
#include <vector>
#include "Enemy.h"
#include "CrumbleBulletShootable.h"
class Enemy2 : public Enemy, public CrumbleBulletShootable
{
public:
	Enemy2(const std::string& objectName, const MathPoint& startingPoint, const std::vector<MathPoint>& corners);
	void action(double timeGain) override;
};
