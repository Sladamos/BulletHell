#pragma once
class MathVector;
class MathPoint
{
public:
	MathPoint();
	MathPoint(int x, int y);
	MathPoint(const MathPoint& changedMathPoint, const MathPoint& newCenter);
	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);
	void setCoordinates(int x, int y);
	MathPoint& moveByVector(const MathVector& vector);
private:
	int x, y;
};

