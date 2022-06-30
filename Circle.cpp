#include "Circle.h"

Circle::Circle(int radius) : radius(radius), Shape() 
{
	calculateOutermostCoordinates();
}

void Circle::calculateOutermostCoordinates()
{
	mostTopCoordinate = mostBottomCoordinate = radius;
	mostRightCoordinate = mostLeftCoordinate = radius;
}

