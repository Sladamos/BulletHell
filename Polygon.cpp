#include "Polygon.h"
using namespace std;

Polygon::Polygon(const vector<Point>& corners) : corners(corners), Shape()
{
	calculateOutermostCoordinates();
}

void Polygon::calculateOutermostCoordinates()
{
	calculateMostTopCoordinate();
	calculateMostRightCoordinate();
	calculateMostBottomCoordinate();
	calculateMostLeftCoordinate();
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
