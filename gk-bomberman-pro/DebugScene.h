#pragma once
#include "Scene.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "PrimitiveRenderer.h"
#include "LineSegment.h"

/*!
 * @brief Klasa reprezentujaca scene do testowania roznych aspektow silnika gry
*/
class DebugScene :
    public Scene
{
private:
	//! Kolejka zdarzen 
	ALLEGRO_EVENT_QUEUE* eventQueue;
	//! Klasa do renderowania prymitywow
	PrimitiveRenderer renderer;
	//! Zmienna pomocnicza
	int i = 10;
public:
	/*!
	 * @brief Renderuje scene
	*/
	virtual void render();
	/*!
	 * @brief Inicjalizuje scene
	*/
	virtual void show();
	/*!
	 * @brief Sprzata pozostalosci po scenie
	*/
	virtual void dispose();
};

