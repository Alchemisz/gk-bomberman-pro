#pragma once
class PlayerConfiguration
{
private:
	int moveUP,
		moveDOWN,
		moveLEFT,
		moveRIGHT,
		putBomb;
public:
	PlayerConfiguration(int moveUP, int moveDOWN, int moveLEFT, int moveRIGHT, int putBomb);
	void setMoveUP(int moveUP);
	void setMoveDOWN(int moveDOWN);
	void setMoveLEFT(int moveLEFT);
	void setMoveRIGHT(int moveRIGHT);
	void setPutBomb(int putBomb);
	int getMoveUP();
	int getMoveDOWN();
	int getMoveLEFT();
	int getMoveRIGHT();
	int getPutBomb();
};

