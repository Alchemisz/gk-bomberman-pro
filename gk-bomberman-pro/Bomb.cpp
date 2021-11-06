#include "Bomb.h"

Bomb::Bomb(int power)
{
	this->power = power;
}

int Bomb::getPower()
{
	return this->power;
}

float Bomb::getX() {
	return this->x;
}

float Bomb::getY() {
	return this->y;
}

void Bomb::setX(float x) {
	this->x = x;
}

void Bomb::setY(float y) {
	this->y = y;
}

bool Bomb::decrementLife()
{
	this->life = this->life - 1;
	return life < 0;
}
