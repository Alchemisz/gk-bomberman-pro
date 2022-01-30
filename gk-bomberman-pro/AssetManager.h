#pragma once
#include <allegro5/allegro.h>
#include <iostream>
#include "Bitmaphandler.h"
#include "PrimitiveAnimation.h"
#include <map>
/*!
 * @brief Klasa do przechowywania zasobow gry
*/
class AssetManager
{
public:
	//! Mapa z zasobami
	static std::map<std::string, ALLEGRO_BITMAP*> bitmapAssets;
	//! Mapa z animacjami
	static std::map<std::string, PrimitiveAnimation*> animationAssets;
	//! Bitmap handler do obslugi
	static BitmapHandler bitmapHandler;
	/*!
	 * @brief Wczytuje bitmape do menagera
	 * @param key Klucz bitmapy
	 * @param path Sciezka do pliku
	*/
	static void loadBitmap(std::string key, std::string path);
	/*!
	 * @brief Wczytuje animacje do menagera
	 * @param key Klucz animacji
	 * @param path Sciezka
	 * @param frames Ilosc klatek animacji
	 * @param rows Ilosc rzedow animacji
	 * @param stepDelay Opoznienie miedzy klatkami
	 * @param x Wspolrzedna x
	 * @param y Wspolrzedna y
	*/
	static void loadAnimation(std::string key, std::string path, int frames, int rows, int stepDelay, int x, int y);
	/*!
	 * @brief Usuwa bitmape z menadzera
	 * @param key Klucz bitmapy
	*/
	static void freeBitmap(std::string key);
	/*!
	 * @brief Usuwa animacje z menadzera
	 * @param key Klucz animacji
	*/
	static void freeAnimation(std::string key);
};

