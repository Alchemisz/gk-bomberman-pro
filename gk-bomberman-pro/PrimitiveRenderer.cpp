#include "PrimitiveRenderer.h"

void PrimitiveRenderer::line(Point2D p0, Point2D p1, ALLEGRO_COLOR colour)
{
	int x;
	float y, m;

	int dy = p1.getY() - p0.getY();
	int dx = p1.getX() - p0.getX();
	m = (float) dy / dx;
	y = p0.getY();
	
	for (x = p0.getX(); x <= p1.getX(); x++)
	{
		al_put_pixel(x, (int)(y + 0.5), colour);
		y += m;
	}
}

/*void PrimitiveRenderer::line(Point2D p0, Point2D p1, ALLEGRO_COLOR colour)
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
}*/
