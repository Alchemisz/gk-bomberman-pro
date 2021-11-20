#pragma once
class TransformableObject
{
	virtual void translate(int x, int y);
	virtual void rotate(float alpha);
	virtual void scale(float factor);
};

