#include "MathPoint.h"
#include "MathVector.h"
MathPoint::MathPoint() : x(0), y(0) {}

MathPoint::MathPoint(int x, int y) : x(x), y(y) {}

MathPoint::MathPoint(const MathPoint& changedMathPoint, const MathPoint& newCenter) : x(changedMathPoint.getX() - newCenter.getX()), y(changedMathPoint.getY() - newCenter.getY()) {}

int MathPoint::getX() const
{
	return x;
}

int MathPoint::getY() const
{
	return y;
}

void MathPoint::setX(int x)
{
	this->x = x;
}

void MathPoint::setY(int y)
{
	this->y = y;
}

void MathPoint::setCoordinates(int x, int y)
{
	this->x = x;
	this->y = y;
}

MathPoint& MathPoint::moveByVector(const MathVector& vector)
{
	this->x += vector.getXLength();
	this->y += vector.getYLength();
	return *this;
}