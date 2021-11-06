#pragma once
#include "Player.h"
class Explosion
{
	private:
		float x, y;
		direction dir;
	public:
		int _x, _y;
		void setX(float x);
		void setY(float y);
		void setDir(direction dir);
		direction getDir();
		float getX();
		float getY();
		void drawExplosion();
};

