#pragma once
class Point
{
public:
	Point();
	Point(int x, int y);
	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);
	void setCoordinates(int x, int y);
	Point& moveByVector(int x, int y);
private:
	int x, y;
};

