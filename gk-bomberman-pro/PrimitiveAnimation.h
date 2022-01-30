#pragma once
#include <allegro5/allegro.h>

/*!
 * @brief Klasa do tworzenia animacji
*/
class PrimitiveAnimation
{
private:
	//! Animacja
	ALLEGRO_BITMAP* Animation;
	//! Ilosc klatek animacji
	int frames;
	//! Ilosc klatek opoznienia miedzy klatkami animacji
	int stepdelay;
	//! Wysokosc grafiki
	int height;
	//! Szerokosc grafiki
	int width;
	//! Obecna klatka animacji
	int frametime;
	//! Rzedy animacji
	int rows;
public:
	/*!
	 * @brief Konstruktor domyslny animacji
	 * @param filepath Sciezka do pliku
	 * @param frames Ilosc klatek animacji
	 * @param rows Ilosc rzedow animacji
	 * @param stepdelay Opoznienie w animacji
	 * @param height Wysokosc grafiki
	 * @param width Szerokosc grafiki
	*/
	PrimitiveAnimation(const char* filepath, int frames,int rows, int stepdelay, int height, int width);
	/*!
	 * @brief Rysuje obecna klatke animacji w danym miejscu
	 * @param x Wspolrzedna x
	 * @param y Wspolrzedna y
	 * @param row Rzad animacji
	*/
	void drawAnimation(int x,int y,int row);
	/*!
	 * @brief Rysuje pierwsza klatke animacji
	 * @param x Wspolrzedna x
	 * @param y Wspolrzedna y
	 * @param row Rzad animacji
	*/
	void drawDefaultPosition(int x, int y,int row);
	/*!
	 * @brief Niszczy animacje
	*/
	void destroyAnimation();
};

