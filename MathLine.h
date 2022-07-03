#pragma once
#include "MathPoint.h"
class MathLine //Ax+By+C=0
{
public:
	MathLine(const MathPoint& firstPoint, const MathPoint& secondPoint);
	int calculateDistance(const MathPoint& point);
private:
	double A, B, C;
};

