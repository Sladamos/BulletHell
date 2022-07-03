#include <math.h>
#include "MathStretch.h"
#include "MathVector.h"

MathStretch::MathStretch(const MathPoint& firstPoint, const MathPoint& secondPoint) : MathLine(firstPoint, secondPoint), firstPoint(firstPoint)
, secondPoint(secondPoint) {}

bool MathStretch::isCircleTangent(const MathPoint& circleCenter, int radius)
{
	return calculateDistance(circleCenter) <= radius && isntTriangleObtuse(circleCenter);
}

bool MathStretch::isntTriangleObtuse(const MathPoint& thirdInterior)
{ //checking only first and second interior (triangle base) - they're important for collisionOccurs
	double a = pow(MathVector(firstPoint, secondPoint).getLength(), 2), b = pow(MathVector(firstPoint, thirdInterior).getLength(), 2),
		c = pow(MathVector(thirdInterior, secondPoint).getLength(), 2);
	double longerSide = b - c > c - b ? b - c : c - b;
	return  a >= longerSide;
}