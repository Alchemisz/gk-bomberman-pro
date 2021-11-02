#pragma once

enum BLOCK_TYPE { AIR, WALL, STONE};

class Block
{
private:
	int x, y;
	BLOCK_TYPE block_type;
	bool hasBomb;
public:
	static const int WIDTH = 20;
	void setX(int x);
	void setY(int y);
	void setBlockType(BLOCK_TYPE block_type);
	int getX();
	int getY();
	void setHasBomb(bool hasBomb);
	bool getHasBomb();
	BLOCK_TYPE getBlockType();
};

