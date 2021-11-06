#pragma once
#include <iostream>
#include "Block.h"

class Bomb
{
private:
	float x, y;
	int life = 9;
	int power;
public:
	Bomb(int power);
	int getPower();
	static const int BOMB_WIDTH = 14;
	float getX();
	float getY();
	void setX(float x);
	void setY(float y);
	bool decrementLife();
};

