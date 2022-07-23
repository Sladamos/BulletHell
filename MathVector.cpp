#include <math.h>
#include "MathVector.h"

MathVector::MathVector(const MathPoint& terminalMathPoint) : initialMathPoint(MathPoint()), terminalMathPoint(terminalMathPoint) {}
MathVector::MathVector(const MathPoint& initialMathPoint, const MathPoint& terminalMathPoint) : initialMathPoint(initialMathPoint), terminalMathPoint(terminalMathPoint) {}

int MathVector::getXLength() const
{
	return terminalMathPoint.getX() - initialMathPoint.getX();
}

int MathVector::getYLength() const
{
	return terminalMathPoint.getY() - initialMathPoint.getY();
}

int MathVector::getLength() const
{
	return sqrt(pow(initialMathPoint.getX() - terminalMathPoint.getX(), 2) + pow(initialMathPoint.getY() - terminalMathPoint.getY(), 2));
} // sqrt(  (xa-xb)^2 + (ya-yb)^2 )

int MathVector::getVectorProductValue(const MathVector& otherVector) const
{
	return getXLength() * otherVector.getYLength() - otherVector.getXLength() * getYLength();
}

MathVector MathVector::operator*(double value) const
{
	return MathVector(terminalMathPoint * value);
}

MathVector MathVector::operator-() const
{
	return MathVector(-terminalMathPoint);
}