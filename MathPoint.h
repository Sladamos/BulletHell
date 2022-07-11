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
	void changeCoordinatesCenter(const MathPoint& newCenter, const MathPoint& currentCenter);
	MathPoint& moveByVector(const MathVector& vector);
	MathPoint& rotate(double angle, const MathPoint& referencePoint);
private:
	int x, y;
};

