#pragma once
#include "Shape.h"
class Circle : public Shape
{
public:
	Circle(int radius);
	bool isCircle() override;
	int getRadius();
private:
	void calculateOutermostCoordinates() override;

	int radius;
};

