#pragma once
#include "Player.h"
/*!
 * @brief Klasa reprezentujaca eksplozje w grze
*/
class Explosion
{
	private:
		//! Wspolrzedna x
		float x; 
		//! Wspolrzedna y
		float y;
		//! Kierunek wybuchu
		direction dir;
		//! Czas zycia wybuchu
		int lifetime = 60;
	public:
		int _x, _y;
		/*!
		 * @brief Ustawia nowa wartosc x
		 * @param x Nowa wartosc x
		*/
		void setX(float x);
		/*!
		 * @brief Ustawia nowa wartosc y
		 * @param y Nowa wartosc y
		*/
		void setY(float y);
		/*!
		 * @brief Ustawia kierunek eksplozji
		 * @param dir Nowy kierunek eksplozji
		*/
		void setDir(direction dir);
		/*!
		 * @brief Zwraca kierunek eksplozji
		 * @return Kierunek eksplocji
		*/
		direction getDir();
		/*!
		 * @brief Zwraca wspolrzedna x
		 * @return Wspolrzedna x
		*/
		float getX();
		/*!
		* @brief Zwraca wspolrzedna y
		* @return Wspolrzedna y
		*/
		float getY();
		/*!
		 * @brief Skraca czas zycia eksplozji
		 * @return Wartosc logiczna mowiaca czy czas zycia eksplozji sie skonczyl
		*/
		bool decreaseLife();
};

