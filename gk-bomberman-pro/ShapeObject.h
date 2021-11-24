#pragma once
#include "TransformableObject.h"
#include "DrawableObject.h"

class ShapeObject :
    public DrawableObject, TransformableObject
{
    virtual void draw();
    virtual void translate(int x, int y);
    virtual void rotate(float alpha);
    virtual void scale(float factor);
};

