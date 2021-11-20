#include "Point2D.h"

Point2D::Point2D(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Point2D::translate(float x, float y)
{
	this->x += x;
	this->y += y;
}

void Point2D::rotate(float alpha)
{
	this->x = this->x * cos(alpha) - this->y * sin(alpha);
	this->y = this->x * sin(alpha) + this->y * cos(alpha);
}

void Point2D::scale(float factor)
{
	this->x *= factor;
	this->y *= factor;
}

Point2D::Point2D()
{
	this->x = 0;
	this->y = 0;
}

float Point2D::getX()
{
	return this->x;
}

float Point2D::getY()
{
	return this->y;
}

void Point2D::setX(float x)
{
	this->x = x;
}

void Point2D::setY(float y)
{
	this->y = y;
}
