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
	for (double a = 0; a < PI / 2; a += 0.01)
	{
		x = r * cos(a);
		y = r * sin(a);

		al_draw_pixel(p.getX() + x, p.getY() + y, colour);
		al_draw_pixel(p.getX() - x, p.getY() + y, colour);
		al_draw_pixel(p.getX() + x, p.getY() - y, colour);
		al_draw_pixel(p.getX() - x, p.getY() - y, colour);

	}
}

void PrimitiveRenderer::elipse_lab(Point2D p, int r1,int r2, ALLEGRO_COLOR colour)
{
	int x, y;
	double PI = 3.141;
	for (double a = 0; a < PI / 2; a += 0.01)
	{
		x = r1 * cos(a);
		y = r2 * sin(a);

		al_draw_pixel(p.getX() + x, p.getY() + y, colour);
		al_draw_pixel(p.getX() - x, p.getY() + y, colour);
		al_draw_pixel(p.getX() + x, p.getY() - y, colour);
		al_draw_pixel(p.getX() - x, p.getY() - y, colour);

	}
}

void PrimitiveRenderer::boundry_fill(Point2D p, ALLEGRO_COLOR fill_color, ALLEGRO_COLOR boundry_color)
{	
	std::stack<Point2D> stack;
	stack.push(p);

	ALLEGRO_BITMAP* tempBitmap = al_clone_bitmap(al_get_backbuffer(al_get_current_display()));
	al_lock_bitmap(tempBitmap,al_get_bitmap_format(tempBitmap) ,ALLEGRO_LOCK_READWRITE);
	al_set_target_bitmap(tempBitmap);

	while (!stack.empty()) {
		Point2D curPoint = stack.top();
		if (curPoint.getX() < 0 || curPoint.getX() > 1280 || curPoint.getY() < 0 || curPoint.getY() > 720) {
			stack.pop();
			continue;
		}
		if (compareColor(al_get_pixel(tempBitmap, curPoint.getX(), curPoint.getY()), fill_color)) {
			stack.pop();
			continue;
		}
		if (compareColor(al_get_pixel(tempBitmap, curPoint.getX(), curPoint.getY()), boundry_color)) {
			stack.pop();
			continue;
		}
		stack.pop();
		al_put_pixel(curPoint.getX(), curPoint.getY(), fill_color);
		stack.push(Point2D(curPoint.getX() + 1, curPoint.getY()));
		stack.push(Point2D(curPoint.getX(), curPoint.getY() + 1));
		stack.push(Point2D(curPoint.getX() - 1, curPoint.getY()));
		stack.push(Point2D(curPoint.getX(), curPoint.getY() - 1));
	}
	al_set_target_backbuffer(al_get_current_display());
	al_unlock_bitmap(tempBitmap);
	al_draw_bitmap(tempBitmap, 0, 0, 0);
	al_destroy_bitmap(tempBitmap);

}

bool PrimitiveRenderer::compareColor(ALLEGRO_COLOR c1, ALLEGRO_COLOR c2)
{	
	unsigned char r1, g1, b1, r2, g2, b2;
	al_unmap_rgb(c1, &r1,&g1,&b1);
	al_unmap_rgb(c2, &r2, &g2, &b2);
	return (r1 == r2) && (g1 == g2) && (b1 == b2);
}



void PrimitiveRenderer::line(Point2D p0, Point2D p1, ALLEGRO_COLOR colour)
{
	int dx, dy, g, h, c;
	dx = p1.getX() - p0.getX();

	if (dx > 0) g = 1; else g = -1;

	dx = abs(dx);
	dy = p1.getY() - p0.getY();
	if (dy > 0) h = 1; else h = -1;
	dy = abs(dy);

	if (dx > dy) {
		c = -1 * dx;
		while (p0.getX() != p1.getX())
		{
			al_put_pixel(p0.getX(), p0.getY(), colour);
			c += (2 * dy);
			if (c > 0) { p0.setY(p0.getY() + h); c -= (2 * dx); }
			p0.setX(p0.getX() + g);
		}
	}
	else {
		c = (-1 * dy);
		while (p0.getY() != p1.getY())
		{
			al_put_pixel(p0.getX(), p0.getY(), colour);
			c += (2 * dx);
			if (c > 0)
			{
				p0.setX(p0.getX() + g);
				c -= (2 * dy);
			}
			p0.setY(p0.getY() + h);
		}
	}
}
