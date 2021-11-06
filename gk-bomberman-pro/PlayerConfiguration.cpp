#include "PlayerConfiguration.h"

PlayerConfiguration::PlayerConfiguration(int moveUP, int moveDOWN, int moveLEFT, int moveRIGHT, int putBomb)
{
	this->moveUP = moveUP;
	this->moveDOWN = moveDOWN;
	this->moveLEFT = moveLEFT;
	this->moveRIGHT = moveRIGHT;
	this->putBomb = putBomb;
}

void PlayerConfiguration::setMoveUP(int moveUP)
{
	this->moveUP = moveUP;
}

void PlayerConfiguration::setMoveDOWN(int moveDOWN)
{
	this->moveDOWN = moveDOWN;
}

void PlayerConfiguration::setMoveLEFT(int moveLEFT)
{
	this->moveLEFT = moveLEFT;
}

void PlayerConfiguration::setMoveRIGHT(int moveRIGHT)
{
	this->moveRIGHT = moveRIGHT;
}

void PlayerConfiguration::setPutBomb(int putBomb)
{
	this->putBomb = putBomb;
}

int PlayerConfiguration::getMoveUP()
{
	return this->moveUP;
}

int PlayerConfiguration::getMoveDOWN()
{
	return this->moveDOWN;
}

int PlayerConfiguration::getMoveLEFT()
{
	return this->moveLEFT;
}

int PlayerConfiguration::getMoveRIGHT()
{
	return this->moveRIGHT;
}

int PlayerConfiguration::getPutBomb()
{
	return this->putBomb;
}