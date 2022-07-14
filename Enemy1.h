#pragma once
#include <string>
#include <vector>
#include "Enemy.h"
#include "FireballShootable.h"
class Enemy1 : public Enemy, public FireballShootable
{
public:
	Enemy1(const std::string& objectName, const MathPoint& startingPoint, const std::vector<MathPoint>& corners);
	void action(double timeGain) override;
};

