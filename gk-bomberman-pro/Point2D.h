#pragma once
class Point2D
{
private:
	int x, y;

public:
	Point2D(int x, int y);
	Point2D();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
};

