#include "Circle.h"

Circle::Circle(int radius) : radius(radius), Shape() 
{
	calculateOutermostCoordinates();
}

bool Circle::isCircle()
{
	return true;
}

int Circle::getRadius()
{
	return radius;
}

void Circle::calculateOutermostCoordinates()
{
	mostRightCoordinate = mostBottomCoordinate =  radius;
	mostTopCoordinate = mostLeftCoordinate = -radius;
}

