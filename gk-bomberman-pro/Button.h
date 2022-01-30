#pragma once
#include <allegro5/allegro_primitives.h>
#include "Color.h"
#include <iostream>
#include "Mouse.h"

/*!
 * @brief Klasa reprezentujaca przycisk
*/
class Button
{
private:
	//! Wspolrzedna x
	int x;
	//! Wspolrzedna y
	int y;
	//! Tekst w przycisku
	std::string text;
	//! Kolor przycisku
	ALLEGRO_COLOR buttonColor;
	//! Kolor ramki przycisku
	ALLEGRO_COLOR frameColor;
	//! Wielkosc marginesu
	const int FRAME_MARGIN = 10;
public:
	//! Szerokosc przycisku
	static const int BUTTON_WIDTH = 240;
	//! Wysokosc przycisku
	static const int BUTTON_HEIGHT = 60;
	//! Czy przycisk jest podswietlany przez mysz
	bool hover = false;
	//! Metoda wykonywana przez nacisniecie
	void (*handler)(void) = 0;
	/*!
	 * @brief Rysuje przycisk na ekranie
	*/
	void draw();
	/*!
	 * @brief Aktualizuje stan przycisku
	*/
	void update();
	/*!
	 * @brief Tworzy nowy przycisk
	 * @param x Wspolrzedna x
	 * @param y Wspolrzedna y
	*/
	Button(int x, int y);
	/*!
	 * @brief Ustawia metode wywolywana przez nacisniecie
	 * @param handler Funkcja do przekazania
	*/
	void registerEventListener(void (*handler)(void));
	/*!
	 * @brief Ustawia tekst wyswietlany na przycisku
	 * @param text Nowy tekst
	*/
	void setText(std::string text);
	/*!
	 * @brief Zwraca obecny tekst przycisku
	 * @return Tekst przycisku
	*/
	std::string getText();
};

