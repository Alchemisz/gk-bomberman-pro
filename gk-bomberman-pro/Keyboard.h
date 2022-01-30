#pragma once
#include <allegro5/allegro.h>
/*!
 * @brief Klasa obslugujaca klawiature
*/
class Keyboard {
public:
	//! Tablica ze stanami przyciskow
	static bool keys[ALLEGRO_KEY_MAX];
	//! Tablica ze stanami wirtualnych przyciskow
	static bool artificalKeyboard[ALLEGRO_KEY_MAX];
	/*!
	 * @brief Ustawia stan przycisku z klawiatury
	 * @param keyCode Kod przycisku
	 * @param down Stan przycisku
	*/
	static void setDown(int keyCode, bool down);
	/*!
	 * @brief Ustawia stan wirtualnych przyciskow
	 * @param keyCode Kod przycisku
	*/
	static void artificialSetDown(int keyCode);
	/*!
	 * @brief Sprawdza stan przycisku z klawiatury
	 * @param keyCode Kod przycisku
	 * @return Wartosc logiczna sprawdzajaca czy przycisk jest nacisniety
	*/
	static bool isKeyDown(int keyCode);
};