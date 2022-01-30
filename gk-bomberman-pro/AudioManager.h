#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <vector>
#include <iostream>
#include <random>

/*!
 * @brief Klasa do zarzadzania efektami dzwiekowymi
*/
class AudioManager
{
private:
	//!Czy muzyka jest wlaczona
	bool active = true; 
	//!Muzyka
	ALLEGRO_SAMPLE* MUSIC;
	//!Muzyka w menu
	ALLEGRO_SAMPLE* MENU_MUSIC;
	//!Efekt dzwiekowy po straconym zyciu
	ALLEGRO_SAMPLE* BOOM;
	//!Efekty dzwiekowe eksplocji
	std::vector<ALLEGRO_SAMPLE*> EXPLOSION;
	//!Zmienna pomocnicza do losowosci
	unsigned int randCount = 0;
	//!Wskaznik na instancje klasy
	static AudioManager* audioManger;
	//!Konstruktor
	AudioManager();
	//!Wskaznik na efekt dzwiekowy
	ALLEGRO_SAMPLE_ID SAMPLE_POINTER;
public:
	/*!
	 * @brief Tworzy nowa instancje klasy lub pobiera obecna
	 * @return Wskaznik na instancje klasy
	*/
	static AudioManager* getInstance();
	/*!
	 * @brief Odtwarza wybrany efekt dzwiekowy
	 * @param sample_name Nazwa efektu dzwiekowego
	*/
	void Play(std::string sample_name);
	/*!
	 * @brief Zatrzymuje wszystkie efekty dzwiekowe
	*/
	void stopAllSamples();
};

