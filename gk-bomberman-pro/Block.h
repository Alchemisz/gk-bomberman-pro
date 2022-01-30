#pragma once
//!Typ bloczku
enum BLOCK_TYPE { AIR, WALL, STONE};
/*!
 * @brief Klasa reprezentujaca obiekt bloczku w grze
*/
class Block
{
private:
	//! Wspolrzedna x
	int x;
	//! Wspolrzedna y
	int y;
	//! Typ bloczku
	BLOCK_TYPE block_type;
	//! Czy bloczek zawiera bombe
	bool hasBomb;
public:
	//! Szerokosc bloczka
	static const int WIDTH = 20;
	/*!
	 * @brief Ustawia wartosc wspolrzednej x
	 * @param x Nowa wartosc
	*/
	void setX(int x);
	/*!
	 * @brief Ustawia wartosc wspolrzednej y
	 * @param y Nowa wartosc
	*/
	void setY(int y);
	/*!
	 * @brief Ustawia nowy typ bloczka
	 * @param block_type Nowy typ bloczka
	*/
	void setBlockType(BLOCK_TYPE block_type);
	/*!
	 * @brief Zwraca wspolrzedna x bloczku
	 * @return Wspolrzedna x bloczku
	*/
	int getX();
	/*!
	* @brief Zwraca wspolrzedna y bloczku
	* @return Wspolrzedna y bloczku
	*/
	int getY();
	/*!
	 * @brief Ustawia wartosc zawierania bomby w bloczku
	 * @param hasBomb Nowa wartosc zawierania bomby w bloczku
	*/
	void setHasBomb(bool hasBomb);
	/*!
	 * @brief Zwraca, czy bloczek zawiera bombe
	 * @return Wartosc logiczna odpowiadajaca, czy bloczek zawiera bombe
	*/
	bool getHasBomb();
	/*!
	 * @brief Zwraca typ bloczku
	 * @return Typ bloczku
	*/
	BLOCK_TYPE getBlockType();
};

