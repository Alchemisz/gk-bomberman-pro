#pragma once
#include "EngineConfiguration.h"
#include <allegro5/allegro.h>
#include <allegro5/timer.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <string>
#include "Scene.h"
#include "PrimitiveRenderer.h"
#include "MainMenuScene.h"
#include "SceneManager.h"
#include <allegro5/allegro_image.h>
#include "Keyboard.h"
#include "Mouse.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>


/*!
 * @brief Klasa glowna silnika
*/
class Engine
{
public:
	/*!
	 * @brief Czysci ekran podanym kolorem
	 * @param color Kolor
	*/
	void clearScreen(ALLEGRO_COLOR color);
	/*!
	 * @brief Wyswietla blad z dana trescia
	 * @param title Tytul
	 * @param heading Naglowek
	 * @param errorMsg Wiadomosc
	*/
	void errorMessage(std::string title, std::string heading, std::string errorMsg);
	/*!
	 * @brief Inicjalizuje silnik
	*/
	void init();
	/*!
	 * @brief Petla glowna silnika
	*/
	void loop();
	/*!
	 * @brief Zamyka silnik
	*/
	void close();
	/*!
	 * @brief Zwraca domyslna czcionke
	 * @return Czcionka
	*/
	ALLEGRO_FONT* getFont();
	/*!
	 * @brief Zwraca lub tworzy nowa instacje klasy
	 * @return Nowa lub istniejaca instancja klasy
	*/
	static Engine* getInstance();
	//! Wskaznik na silnik
	static Engine* engine;
	/*!
	 * @brief Konstruktor domyslny z konfiguracja silnika
	 * @param config Konfiguracja silnika
	*/
	Engine(EngineConfiguration config);
protected:
private:
	//! Konfiguracja silnika
	EngineConfiguration config;
	//! Wskaznik na ekran
	ALLEGRO_DISPLAY* display;
	//! Czasomierz stalej ilosci klatek
	ALLEGRO_TIMER* loopTimer;
	//! Kolejka zdarzen
	ALLEGRO_EVENT_QUEUE* eventQueue;
	//! Kolejka zdarzen petli
	ALLEGRO_EVENT_QUEUE* loopQueue;
	//! Wskaznik na czcionke 
	ALLEGRO_FONT* font;
};








