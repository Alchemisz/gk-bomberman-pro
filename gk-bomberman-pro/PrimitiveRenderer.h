#include "Point2D.h"
#include <allegro5/allegro.h>
#pragma once
class PrimitiveRenderer
{
public:
	void line(Point2D p0, Point2D p1, ALLEGRO_COLOR colour);
};

