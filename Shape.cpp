#include "Shape.h"
using namespace std;

Shape::Shape() : mostTopCoordinate(0), mostRightCoordinate(0), mostBottomCoordinate(0), mostLeftCoordinate(0)
{
}

int Shape::getMostTopCoordinate()
{
	return mostTopCoordinate;
}

int Shape::getMostRightCoordinate()
{
	return mostRightCoordinate;
}

int Shape::getMostBottomCoordinate()
{
	return mostBottomCoordinate;
}

int Shape::getMostLeftCoordinate()
{
	return mostLeftCoordinate;
}