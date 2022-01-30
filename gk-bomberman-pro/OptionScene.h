#pragma once
#include "Scene.h"
#include "Button.h"
#include "SceneManager.h"
#include "MainMenuScene.h"

/*!
 * @brief Klasa reprezentujaca scene pomocy
*/
class OptionScene : public Scene
{
private:
	//! Przycisk powrotu
	Button* button;
	//! Grafika tla
	ALLEGRO_BITMAP* help_screen;

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
	 * @brief Sprzata smieci po scenie
	*/
	virtual void dispose();
};

