#pragma once
class Shape
{
public:
	Shape();
	virtual bool isCircle();
	virtual bool isPolygon();
	int getMostTopCoordinate();
	int getMostRightCoordinate();
	int getMostBottomCoordinate();
	int getMostLeftCoordinate();
protected:
	virtual void calculateOutermostCoordinates() = 0;

	int mostTopCoordinate, mostRightCoordinate, mostBottomCoordinate, mostLeftCoordinate;
};

