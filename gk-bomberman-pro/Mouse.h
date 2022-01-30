#pragma once
/*!
 * @brief Klasa do obslugi myszy
*/
class Mouse
{
public:
	//! Wspolrzedna x myszy
	static int x;
	//! Wspolrzedna y myszy
	static int y;
	//! Wartosc logiczna przycisniecia przycisku myszy
	static bool mouseDown;
	//! Wartosc logiczna podnoszenia palca z przycisku myszy
	static bool mouseUp;
};

