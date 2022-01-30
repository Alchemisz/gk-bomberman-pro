#pragma once
#include <iostream>
#include "Block.h"

/*!
 * @brief Klasa reprezentujaca bombe w grze
*/
class Bomb
{
private:
	//! Wspolrzedna x
	float x;
	//! Wspolrzedna y
	float y;
	//! Czas zycia bomby zanim eksploduje
	int life = 9;
	//! Zasieg eksplozji bomby
	int power;
public:
	/*!
	 * @brief Konstruktor bomby z zasiegiem eksplozji
	 * @param power Zasieg eksplozji
	*/
	Bomb(int power);
	/*!
	 * @brief Zwraca zasieg eksplozji bomby
	 * @return Zasieg eksplozji
	*/
	int getPower();
	//!brief Szerokosc bomby
	static const int BOMB_WIDTH = 14;
	/*!
	 * @brief Zwraca wspolrzedna x bomby
	 * @return Wspolrzedna x
	*/
	float getX();
	/*!
	* @brief Zwraca wspolrzedna y bomby
	* @return Wspolrzedna y
	*/
	float getY();
	/*!
	 * @brief Zwraca czas zycia bomby
	 * @return Czas zycia bomby
	*/
	int getLife();
	/*!
	 * @brief Ustawia wspolrzedna x bomby
	 * @param x Nowa wartosc x
	*/
	void setX(float x);
	/*!
	* @brief Ustawia wspolrzedna y bomby
	* @param x Nowa wartosc y
	*/
	void setY(float y);
	/*!
	 * @brief Zmniejsza czas zycia bomby o 1
	 * @return Zwraca, czy czas zycia bomby dobiegl konca
	*/
	bool decrementLife();
};

