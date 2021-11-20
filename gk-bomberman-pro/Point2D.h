#pragma once
#include "TransformableObject.h"
#include <Math.h>
class Point2D : public TransformableObject
{
private:
	float x, y;

public:
	Point2D(float x, float y);
	virtual void translate(float x, float y);
	virtual void rotate(float alpha);
	virtual void scale(float factor);
	Point2D();
	float getX();
	float getY();
	void setX(float x);
	void setY(float y);
};

