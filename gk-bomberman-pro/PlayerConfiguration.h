#pragma once
#include "PrimitiveAnimation.h"

/*!
 * @brief Klasa zawierajaca konfiguracje gracza
*/
class PlayerConfiguration
{
private:
	int moveUP,
		moveDOWN,
		moveLEFT,
		moveRIGHT,
		putBomb;
public:
	/*!
	 * @brief Konstruktor do konfiguracji
	 * @param moveUP przycisk do poruszania w gore
	 * @param moveDOWN przycisk do poruszania w dol
	 * @param moveLEFT przycisk do poruszania w lewo
	 * @param moveRIGHT przycisk do poruszania w prawo
	 * @param putBomb przycisk do stawiania bomby
	 * @param anim animacja
	*/
	PlayerConfiguration(int moveUP, int moveDOWN, int moveLEFT, int moveRIGHT, int putBomb, PrimitiveAnimation* anim);
	//! Animacja
	PrimitiveAnimation* animation;
	/*!
	 * @brief Ustawia przycisk do poruszania w gore
	 * @param moveUP Nowy przycisk
	*/
	void setMoveUP(int moveUP);
	/*!
	* @brief Ustawia przycisk do poruszania w dol
	* @param moveUP Nowy przycisk
	*/
	void setMoveDOWN(int moveDOWN);
	/*!
	* @brief Ustawia przycisk do poruszania w lewo
	* @param moveUP Nowy przycisk
	*/
	void setMoveLEFT(int moveLEFT);
	/*!
	* @brief Ustawia przycisk do poruszania w prawo
	* @param moveUP Nowy przycisk
	*/
	void setMoveRIGHT(int moveRIGHT);
	/*!
	 * @brief Ustawia przycisk do stawiania bomby
	 * @param putBomb Nowy przycisk
	*/
	void setPutBomb(int putBomb);
	/*!
	 * @brief Zwraca przycisk do poruszania sie w gore
	 * @return Kod przycisku
	*/
	int getMoveUP();
	/*!
	* @brief Zwraca przycisk do poruszania sie w dol
	* @return Kod przycisku
	*/
	int getMoveDOWN();
	/*!
	* @brief Zwraca przycisk do poruszania sie w lewo
	* @return Kod przycisku
	*/
	int getMoveLEFT();
	/*!
	* @brief Zwraca przycisk do poruszania sie w prawo
	* @return Kod przycisku
	*/
	int getMoveRIGHT();
	/*!
	* @brief Zwraca przycisk do stawiania bomby
	* @return Kod przycisku
	*/
	int getPutBomb();
	/*!
	* @brief Zwraca animacje gracza
	* @return Animacja
	*/
	PrimitiveAnimation* getAnimation();
};

