#include "Polygon.h"
using namespace std;

Polygon::Polygon(const vector<MathPoint>& corners) : corners(corners), Shape()
{
	calculateOutermostCoordinates();
}

bool Polygon::isPolygon()
{
	return true;
}

const vector<MathPoint>& Polygon::getCorners()
{
	return corners;
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
	for (MathPoint corner : corners)
		if (corner.getY() < mostTopCoordinate)
			mostTopCoordinate = corner.getY();
}

void Polygon::calculateMostRightCoordinate()
{
	for (MathPoint corner : corners)
		if (corner.getX() > mostRightCoordinate)
			mostRightCoordinate = corner.getX();
}

void Polygon::calculateMostBottomCoordinate()
{
	for (MathPoint corner : corners)
		if (corner.getY() > mostBottomCoordinate)
			mostBottomCoordinate = corner.getY();
}

void Polygon::calculateMostLeftCoordinate()
{
	for (MathPoint corner : corners)
		if (corner.getX() < mostLeftCoordinate)
			mostLeftCoordinate = corner.getX();
}
