#pragma once

enum BLOCK_TYPE { AIR, WALL, STONE};

class Block
{
private:
	int x, y;
	BLOCK_TYPE block_type;

public:
	static const int WIDTH = 20;
	void setX(int x);
	void setY(int y);
	void setBlockType(BLOCK_TYPE block_type);
	int getX();
	int getY();
	BLOCK_TYPE getBlockType();
	
};

