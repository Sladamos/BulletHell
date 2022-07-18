#pragma once
#include "MoveableEnemy.h"
class Enemy3 : public MoveableEnemy
{
public:
	Enemy3(const std::string& objectName, int numberOfFrames, const MathPoint& startingPoint, const std::vector<MathPoint>& corners);
	void action(double timeGain) override;
};

