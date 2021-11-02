#include "Block.h"

void Block::setX(int x) {
	this->x = x;
}

void Block::setY(int y) {
	this->y = y;
}

int Block::getX() {
	return this->x;
}

int Block::getY() {
	return this->y;
}

void Block::setHasBomb(bool hasBomb)
{
	this->hasBomb = hasBomb;
}

bool Block::getHasBomb()
{
	return this->hasBomb;
}


void Block::setBlockType(BLOCK_TYPE block_type) {
	this->block_type = block_type;
}

BLOCK_TYPE Block::getBlockType() {
	return this->block_type;
}
