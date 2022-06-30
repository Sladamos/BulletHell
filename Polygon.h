#pragma once
#include <vector>
#include "Shape.h"
#include "Point.h"
class Polygon : public Shape
{	
public:
	Polygon(const std::vector<Point>& corners);
private:
	void calculateOutermostCoordinates() override;
	void calculateMostTopCoordinate();
	void calculateMostRightCoordinate();
	void calculateMostBottomCoordinate();
	void calculateMostLeftCoordinate();

	std::vector<Point> corners;
};

