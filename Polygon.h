#pragma once
#include <vector>
#include "Point.h"
class Polygon
{	
public:
	Polygon(int radius);
	Polygon(const std::vector<Point>& corners);
	int getMostTopCoordinate();
	int getMostRightCoordinate();
	int getMostBottomCoordinate();
	int getMostLeftCoordinate();
private:
	void calculateMostTopCoordinate();
	void calculateMostRightCoordinate();
	void calculateMostBottomCoordinate();
	void calculateMostLeftCoordinate();

	int radius;
	int mostTopCoordinate, mostRightCoordinate, mostBottomCoordinate, mostLeftCoordinate;
	std::vector<Point> corners;
};

