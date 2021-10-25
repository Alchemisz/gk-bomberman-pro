#include "Point2D.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <vector>
#pragma once
class PrimitiveRenderer
{
public:
	void line(Point2D p0, Point2D p1, ALLEGRO_COLOR colour);
	void rectangle(Point2D p0, Point2D p1, ALLEGRO_COLOR colour, bool filled);
	void circle(Point2D p,int radius, ALLEGRO_COLOR colour, bool filled);
	void triangle(Point2D p1, Point2D p2, Point2D p3, ALLEGRO_COLOR colour, bool filled);
	void singlePoint(Point2D p, ALLEGRO_COLOR colour);
	void polygonalChain(std::vector<Point2D> chain, ALLEGRO_COLOR colour, bool closed);
};

