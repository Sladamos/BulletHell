#include "Point.h"
Point::Point() : x(0), y(0) {}

Point::Point(int x, int y) : x(x), y(y) {}

int Point::getX() const
{
	return x;
}

int Point::getY() const
{
	return y;
}

void Point::setX(int x)
{
	this->x = x;
}

void Point::setY(int y)
{
	this->y = y;
}

void Point::setCoordinates(int x, int y)
{
	this->x = x;
	this->y = y;
}

Point& Point::moveByVector(int x, int y)
{
	this->x += x;
	this->y += y;
	return *this;
}