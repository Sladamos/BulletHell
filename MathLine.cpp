#include <cmath>
#include "MathLine.h"

MathLine::MathLine(const MathPoint& firstPoint, const MathPoint& secondPoint)
{
	B = firstPoint.getX() - secondPoint.getX() == 0 ? 0 : 1;
	A = B == 0 ? 1 : (secondPoint.getY() - firstPoint.getY()) / (firstPoint.getX() - secondPoint.getX());
	C = B == 0 ? -firstPoint.getX() * A : -(firstPoint.getX() * A + firstPoint.getY());
}

int MathLine::calculateDistance(const MathPoint& point)
{
	return abs(A * point.getX() + B * point.getY() + C) / sqrt(pow(A, 2) + pow(B, 2));
} // |Ax+By+C|/sqrt(A^2+B^2)