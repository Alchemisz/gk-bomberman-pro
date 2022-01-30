#pragma once
/*!
 * @brief Klasa zawierajaca konfiguracje silnika
*/
class EngineConfiguration
{
private:
	//! Szerokosc ekranu
	int width;
	//! Wysokosc ekranu
	int height;
	//! Ilosc klatek na sekunde
	int FPS;
public:
	//! Parametr dzialania klawiatury
	bool keyboard;
	//! Parametr dzialania myszy
	bool mouse;
	//! Parametr dzialania pelnego ekranu
	bool isFullScreen;
	/*!
	 * @brief Zwraca domyslna konfiguracje silnika
	 * @return Domyslna konfiguracja silnika
	*/
	static EngineConfiguration getDefault();
	/*!
	 * @brief Ustawia wartosc wysokosci ekranu
	 * @param value Nowa wartosc
	*/
	void setHeight(int value);
	/*!
	* @brief Ustawia wartosc szerokosci ekranu
	* @param value Nowa wartosc
	*/
	void setWidth(int value);
	/*!
	* @brief Ustawia wartosc klatek na sekunde ekranu
	* @param value Nowa wartosc
	*/
	void setFPS(int value);
	/*!
	 * @brief Zwraca wartosc wysokosci ekranu
	 * @return Wartosc wysokosci ekranu
	*/
	int getHeight();
	/*!
	* @brief Zwraca wartosc szerokosci ekranu
	* @return Wartosc szerokosci ekranu
	*/
	int getWidth();
	/*!
	* @brief Zwraca wartosc klatek na sekunde ekranu
	* @return Wartosc klatek na sekunde ekranu
	*/
	int getFPS();
};
