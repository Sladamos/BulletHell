#include <limits>
#include "Polygon.h"
using namespace std;

Polygon::Polygon(int radius) : radius(radius) 
{
	mostTopCoordinate = mostBottomCoordinate = radius;
	mostRightCoordinate = mostLeftCoordinate = radius;
}

Polygon::Polygon(const vector<Point>& corners) : corners(corners), radius(0),
mostTopCoordinate(numeric_limits<int>::max()), mostRightCoordinate(0), mostBottomCoordinate(0),
mostLeftCoordinate(numeric_limits<int>::max())
{
	calculateMostTopCoordinate();
	calculateMostRightCoordinate();
	calculateMostBottomCoordinate();
	calculateMostLeftCoordinate();
}

int Polygon::getMostTopCoordinate()
{
	return mostTopCoordinate;
}

int Polygon::getMostRightCoordinate()
{
	return mostRightCoordinate;
}

int Polygon::getMostBottomCoordinate()
{
	return mostBottomCoordinate;
}

int Polygon::getMostLeftCoordinate()
{
	return mostLeftCoordinate;
}

void Polygon::calculateMostTopCoordinate()
{
	for (Point corner : corners)
		if (corner.getY() < mostTopCoordinate)
			mostTopCoordinate = corner.getY();
}

void Polygon::calculateMostRightCoordinate()
{
	for (Point corner : corners)
		if (corner.getX() > mostRightCoordinate)
			mostRightCoordinate = corner.getX();
}

void Polygon::calculateMostBottomCoordinate()
{
	for (Point corner : corners)
		if (corner.getY() > mostBottomCoordinate)
			mostBottomCoordinate = corner.getY();
}

void Polygon::calculateMostLeftCoordinate()
{
	for (Point corner : corners)
		if (corner.getX() < mostLeftCoordinate)
			mostLeftCoordinate = corner.getX();
}
