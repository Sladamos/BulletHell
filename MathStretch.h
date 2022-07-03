#pragma once
#include "MathLine.h"
class MathStretch : public MathLine
{
public:
	MathStretch(const MathPoint& firstPoint, const MathPoint& secondPoint);
	bool isCircleTangent(const MathPoint& circleCenter, int radius);
private:
	bool isntTriangleObtuse(const MathPoint& thirdInterior);
	MathPoint firstPoint, secondPoint;
};

