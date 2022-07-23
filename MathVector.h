#pragma once
#include "MathPoint.h"
class MathVector
{
public:
	MathVector(const MathPoint& terminalMathPoint);
	MathVector(const MathPoint& initialMathPoint, const MathPoint& terminalMathPoint);
	int getVectorProductValue(const MathVector& otherVector) const;
	int getXLength() const;
	int getYLength() const;
	int getLength() const;
	MathVector operator*(double value) const;
	MathVector operator-() const;
private:
	MathPoint initialMathPoint, terminalMathPoint;
};

