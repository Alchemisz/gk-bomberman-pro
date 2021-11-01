#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
#include "Block.h"
class Player
{
private:
	float x, y;
	float velocity = 1;

public:
	static const int PLAYER_WIDTH = 14;
	void move();
	void drawPlayer();
	void putBomb();
	void setX(float x);
	void setY(float y);
	void setVelocity(float newVelocity);
	float getVelocity();
	float getX();
	float getY();
	std::pair<int, int> getBlockIndex();
};

