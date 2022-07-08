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
	MathPoint otherFirstPoint = otherStretch.getFirstPoint(), otherSecondPoint = otherStretch.getSecondPoint();	//A and B
	int ABxAC = MathVector(otherFirstPoint, otherSecondPoint).getVectorProductValue(MathVector(otherFirstPoint, firstPoint));	//firstPoint: C
	int ABxAD = MathVector(otherFirstPoint, otherSecondPoint).getVectorProductValue(MathVector(otherFirstPoint, secondPoint));	//secondPoint: D
	int CDxCA = MathVector(firstPoint, secondPoint).getVectorProductValue(MathVector(firstPoint, otherFirstPoint));
	int CDxCB = MathVector(firstPoint, secondPoint).getVectorProductValue(MathVector(firstPoint, otherSecondPoint));

	if ((ABxAC > 0 && ABxAD < 0 || ABxAC < 0 && ABxAD > 0) && (CDxCA > 0 && CDxCB < 0 || CDxCA < 0 && CDxCB>0))
		return true;
	
	if (ABxAC == 0 && otherStretch.contains(firstPoint)) return true;
	if (ABxAD == 0 && otherStretch.contains(secondPoint)) return true;
	if (CDxCA == 0 && contains(otherFirstPoint)) return true;
	if (CDxCB == 0 && contains(otherSecondPoint)) return true;
	return false;
}

bool MathStretch::intersetsWithAnyStretch(const std::vector<MathPoint>& stretchesCorners)
{
	MathPoint previousCollidableCorner = stretchesCorners.back();
	for (MathPoint collidableCorner : stretchesCorners)
	{
		if (intersets(MathStretch(collidableCorner, previousCollidableCorner)))
			return true;
		previousCollidableCorner = collidableCorner;
	}
	return false;
}

bool MathStretch::contains(const MathPoint& point) const
{
	return std::min(firstPoint.getX(), secondPoint.getX()) <= point.getX() && point.getX() <= std::max(firstPoint.getX(), secondPoint.getX()) &&
		std::min(firstPoint.getY(), secondPoint.getY()) <= point.getY() && point.getY() <= std::max(firstPoint.getY(), secondPoint.getY());
}