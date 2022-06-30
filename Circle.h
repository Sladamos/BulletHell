#pragma once
#include "Shape.h"
class Circle : public Shape
{
public:
	Circle(int radius);
private:
	void calculateOutermostCoordinates() override;

	int radius;
};

