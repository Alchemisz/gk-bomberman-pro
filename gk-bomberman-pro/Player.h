#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
#include "Block.h"
#include "PlayerConfiguration.h"

enum direction {
	LEFT = 0,UP,RIGHT,DOWN,CENTER
};


class Player
{
private:
	float x, y;
	float velocity = 1;
	int power = 3;
	bool isMoving;
	int score = 0;
	direction state;
	PlayerConfiguration* playerConfiguration;
public:
	static const int PLAYER_WIDTH = 14;
	void incScore();
	int getScore();
	void move();
	void drawPlayer();
	void putBomb();
	void setX(float x);
	void setY(float y);
	void setVelocity(float newVelocity);
	float getVelocity();
	float getX();
	float getY();
	int getPower();
	void setPower(int power);
	bool getIsMoving();
	void setIsMoving(bool moving);
	direction getPositionState();
	void setPositionState(direction state);
	std::pair<int, int> getBlockIndex();
	PlayerConfiguration* getPlayerConfiguration();
	void setPlayerConfiguration(PlayerConfiguration* playerConfiguration);
};

