#pragma once
/*!
 * @brief Klasa opisujaca punkt w przestrzeni 2D
*/
class Point2D
{
private:
	//! Wspolrzedna x
	int x;
	//! Wspolrzedna y
	int y;

public:
	/*!
	 * @brief Konstruktor punktu z parametrami wspolrzednych
	 * @param x Wspolrzedna x
	 * @param y Wspolrzedna y
	*/
	Point2D(int x, int y);
	/*!
	 * @brief Konstruktor domyslny
	*/
	Point2D();
	/*!
	 * @brief Zwraca wartosc wspolrzednej x
	 * @return Wsporzedna x
	*/
	int getX();
	/*!
	 * @brief Zwraca wartosc wspolrzednej y
	 * @return Wspolrzedna y
	*/
	int getY();
	/*!
	 * @brief Ustawia wartosc wspolrzednej X
	 * @param x Nowa wartosc
	*/
	void setX(int x);
	/*!
	 * @brief Ustawia wartosc wspolrzednej Y
	 * @param y Nowa wartosc
	*/
	void setY(int y);
};

