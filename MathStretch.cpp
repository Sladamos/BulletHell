#include <math.h>
#include <algorithm>
#include "MathStretch.h"
#include "MathVector.h"

MathStretch::MathStretch(const MathPoint& firstPoint, const MathPoint& secondPoint) : MathLine(firstPoint, secondPoint), firstPoint(firstPoint)
, secondPoint(secondPoint) {}

MathPoint MathStretch::getFirstPoint() const
{
	return firstPoint;
}

MathPoint MathStretch::getSecondPoint() const
{
	return secondPoint;
}

bool MathStretch::isCircleTangent(const MathPoint& circleCenter, int radius)
{
	return calculateDistance(circleCenter) <= radius && isntTriangleObtuseAtTheBase(circleCenter);
}

bool MathStretch::isntTriangleObtuseAtTheBase(const MathPoint& thirdInterior)
{
	double base = pow(MathVector(firstPoint, secondPoint).getLength(), 2), b = pow(MathVector(firstPoint, thirdInterior).getLength(), 2),
		c = pow(MathVector(thirdInterior, secondPoint).getLength(), 2);
	double longerSide = b - c > c - b ? b - c : c - b;
	return  base >= longerSide;
}

bool MathStretch::intersets(const MathStretch& otherStretch)
{
	MathPoint otherFirstPoint = otherStretch.getFirstPoint(), otherSecondPoint = otherStretch.getSecondPoint();
	int v1 = MathVector(otherFirstPoint, otherSecondPoint).getVectorProductValue(MathVector(otherFirstPoint, firstPoint));
	int v2 = MathVector(otherFirstPoint, otherSecondPoint).getVectorProductValue(MathVector(otherFirstPoint, secondPoint));
	int v3 = MathVector(firstPoint, secondPoint).getVectorProductValue(MathVector(firstPoint, otherFirstPoint));
	int v4 = MathVector(firstPoint, secondPoint).getVectorProductValue(MathVector(firstPoint, otherSecondPoint));

	if ((v1 > 0 && v2 < 0 || v1 < 0 && v2>0) && (v3 > 0 && v4 < 0 || v3 < 0 && v4>0))
		return true;
	
	if (v1 == 0 && otherStretch.contains(firstPoint)) return true;
	if (v2 == 0 && otherStretch.contains(secondPoint)) return true;
	if (v3 == 0 && contains(otherFirstPoint)) return true;
	if (v4 == 0 && contains(otherSecondPoint)) return true;
	return false;
}

bool MathStretch::contains(const MathPoint& point) const
{
	return std::min(firstPoint.getX(), secondPoint.getX()) <= point.getX() && point.getX() <= std::max(firstPoint.getX(), secondPoint.getX()) &&
		std::min(firstPoint.getY(), secondPoint.getY()) <= point.getY() && point.getY() <= std::max(firstPoint.getY(), secondPoint.getY());
}