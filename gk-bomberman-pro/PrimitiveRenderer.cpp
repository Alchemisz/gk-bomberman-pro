#include "PrimitiveRenderer.h"
#include <cmath>
void PrimitiveRenderer::rectangle(Point2D p0, Point2D p1, ALLEGRO_COLOR colour, bool filled)
{
	if (filled)
		al_draw_filled_rectangle(p0.getX(), p0.getY(), p1.getX(), p1.getY(), colour);
	else 
		al_draw_rectangle(p0.getX(), p0.getY(), p1.getX(), p1.getY(), colour,5);
}

void PrimitiveRenderer::circle(Point2D p, int radius, ALLEGRO_COLOR colour, bool filled)
{
	if (filled)
		al_draw_filled_circle(p.getX(), p.getY(), radius, colour);
	else 
		al_draw_circle(p.getX(), p.getY(), radius, colour,5);
}

void PrimitiveRenderer::triangle(Point2D p1, Point2D p2, Point2D p3, ALLEGRO_COLOR colour, bool filled)
{
	if (filled)
		al_draw_filled_triangle(p1.getX(), p1.getY(), p2.getX(), p2.getY(), p3.getX(), p3.getY(), colour);
	else
		al_draw_triangle(p1.getX(), p1.getY(), p2.getX(), p2.getY(), p3.getX(), p3.getY(), colour,5);
}

void PrimitiveRenderer::singlePoint(Point2D p, ALLEGRO_COLOR colour)
{
	al_draw_pixel(p.getX(), p.getY(), colour);
}

void PrimitiveRenderer::polygonalChain(std::vector<Point2D> chain, ALLEGRO_COLOR colour, bool closed)
{
	for (int i = 0; i < chain.size() - 1; i++)
	{
		line(chain[i], chain[i + 1], colour);
	}
	if (closed)line(chain[chain.size() - 1 ], chain[0],colour);
}

void PrimitiveRenderer::polygonalChain(std::vector<LineSegment> chain, ALLEGRO_COLOR colour, bool closed)
{
	for (int i = 0; i < chain.size(); i++)
	{
		line(chain[i].getBeggining(), chain[i].getEnd(), colour);
		if (i != chain.size() - 1) {
			line(chain[i].getEnd(), chain[i+1].getBeggining(), colour);
		}
	}
	if (closed)
		line(chain[chain.size() - 1].getEnd(), chain[0].getBeggining(), colour);
}

void PrimitiveRenderer::circle_lab(Point2D p, int r, ALLEGRO_COLOR colour)
{
	int x, y;
	double PI = 3.141;
	for (double a = 0; a < PI / 2; a += 0.1)
	{
		x = p.getX() + r * cos(a);
		y = p.getY() + r * sin(a);

		al_put_pixel(x, y, colour);
		al_put_pixel(p.getX() + x, y, colour);
		al_put_pixel(x, p.getY() + y, colour);
		al_put_pixel(p.getX() + x, y + p.getY(), colour);
	}
}



void PrimitiveRenderer::line(Point2D p0, Point2D p1, ALLEGRO_COLOR colour)
{
	int x1 = p0.getX();
	int y1 = p0.getY();
	int x2 = p1.getX();
	int y2 = p1.getY();
	int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;
	dx = x2 - x1;
	dy = y2 - y1;
	dx1 = fabs(dx);
	dy1 = fabs(dy);
	px = 2 * dy1 - dx1;
	py = 2 * dx1 - dy1;
	if (dy1 <= dx1)
	{
		if (dx >= 0)
		{
			x = x1;
			y = y1;
			xe = x2;
		}
		else
		{
			x = x2;
			y = y2;
			xe = x1;
		}
		al_put_pixel(x, y, colour);
		for (i = 0; x < xe; i++)
		{
			x = x + 1;
			if (px < 0)
			{
				px = px + 2 * dy1;
			}
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
				{
					y = y + 1;
				}
				else
				{
					y = y - 1;
				}
				px = px + 2 * (dy1 - dx1);
			}
			al_put_pixel(x, y, colour);
		}
	}
	else
	{
		if (dy >= 0)
		{
			x = x1;
			y = y1;
			ye = y2;
		}
		else
		{
			x = x2;
			y = y2;
			ye = y1;
		}
		al_put_pixel(x, y, colour);
		for (i = 0; y < ye; i++)
		{
			y = y + 1;
			if (py <= 0)
			{
				py = py + 2 * dx1;
			}
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
				{
					x = x + 1;
				}
				else
				{
					x = x - 1;
				}
				py = py + 2 * (dx1 - dy1);
			}
			al_put_pixel(x, y, colour);
		}
	}
}
