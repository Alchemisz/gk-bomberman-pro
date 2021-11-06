#include "Explosion.h"

void Explosion::setX(float x)
{
	this->x = x;
}

void Explosion::setY(float y)
{
	this->y = y;
}

void Explosion::setDir(direction dir)
{
	this->dir = dir;
}

direction Explosion::getDir()
{
	return this->dir;
}

float Explosion::getX()
{
	return this->x;
}

float Explosion::getY()
{
	return this->y;
}
