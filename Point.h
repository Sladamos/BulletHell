#pragma once
class Point
{
public:
	Point();
	Point(int x, int y);
	int getX() const;
	int getY() const;
	void setCoordinates(int x, int y);
	void moveByVertex(int x, int y);
private:
	int x, y;
};

