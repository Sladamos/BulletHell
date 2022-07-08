#pragma once
#include <string>
#include <vector>
#include "Enemy.h"
class Enemy1 : public Enemy
{
public:
	Enemy1(const std::string& objectName, const MathPoint& startingPoint, const std::vector<MathPoint>& corners);
	void action(double timeGain) override;
};

