#pragma once
class Shape
{
public:
	Shape();
	int getMostTopCoordinate();
	int getMostRightCoordinate();
	int getMostBottomCoordinate();
	int getMostLeftCoordinate();
protected:
	virtual void calculateOutermostCoordinates() = 0;

	int mostTopCoordinate, mostRightCoordinate, mostBottomCoordinate, mostLeftCoordinate;
};

