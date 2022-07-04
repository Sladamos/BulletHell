#pragma once
#include "MathLine.h"
class MathStretch : public MathLine
{
public:
	MathStretch(const MathPoint& firstPoint, const MathPoint& secondPoint);
	MathPoint getFirstPoint() const;
	MathPoint getSecondPoint() const;
	bool isCircleTangent(const MathPoint& circleCenter, int radius);
	bool intersets(const MathStretch& otherStretch);
	bool contains(const MathPoint& point) const;
private:
	bool isntTriangleObtuseAtTheBase(const MathPoint& thirdInterior);
	MathPoint firstPoint, secondPoint;
};

