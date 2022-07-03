#pragma once
#include <vector>
#include "Shape.h"
#include "MathPoint.h"
class Polygon : public Shape
{	
public:
	Polygon(const std::vector<MathPoint>& corners);
	bool isPolygon() override;
	const std::vector<MathPoint>& getCorners();
private:
	void calculateOutermostCoordinates() override;
	void calculateMostTopCoordinate();
	void calculateMostRightCoordinate();
	void calculateMostBottomCoordinate();
	void calculateMostLeftCoordinate();

	const std::vector<MathPoint> corners;
};

