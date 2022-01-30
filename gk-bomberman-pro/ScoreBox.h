#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

/*!
 * @brief Klasa reprezentujaca okno wyniku na koncu potyczki
*/
class ScoreBox
{
private:
	//! Czy okno jest aktywne
	bool active = false;
	//! Ilosc klatek przez ktory jest rysowane jeszcze okno
	int framesLeft = 0;
	//! Maksymalna ilosc klatek na ktorych rysowane jest okno
	const int framesActive = 120;
public:
	/*!
	 * @brief Ustawia okno na aktywne, rysujac je na ekranie
	*/
	void setActive();
	/*!
	 * @brief Aktualizuje stan okna
	 * @param GFX_PLR1 Grafika ikony gracza 1
	 * @param GFX_PLR2 Grafika ikony gracza 2
	 * @param score1 Wynik gracza 1
	 * @param score2 Wynik gracza 2
	*/
	void update(ALLEGRO_BITMAP* GFX_PLR1, ALLEGRO_BITMAP* GFX_PLR2, int score1, int score2);
};

