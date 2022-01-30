#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include "SceneManager.h"
#include "DebugScene.h"
#include "Scene.h"
#include "Keyboard.h"
#include "GameScene.h"
#include "Button.h"
#include "Color.h"
#include "Engine.h"
#include "AudioManager.h"
#include "OptionScene.h"

//! Przyciski z menu
enum MENU_BUTTONS {SINGLEPLAYER, MULTIPLAYER, HELP, EXIT};
/*!
 * @brief Klasa reprezentujaca scene menu
*/
class MainMenuScene : public Scene
{
	private:
		//! Przyciski menu
		Button* buttons[4];
		//! Grafika tla
		ALLEGRO_BITMAP* background;
		//! Grafika ozdobna z menu
		ALLEGRO_BITMAP* face;
		//! Grafika ozdobna z menu
		ALLEGRO_BITMAP* logo;
		//! Grafika ozdobna z menu
		ALLEGRO_BITMAP* ricardo_bomberman;
		//! Efekty dzwiekowe 
		AudioManager* Audio;
		//! Animacja tla menu
		PrimitiveAnimation* background_animation;
		/*!
		 * @brief Aktualizuje stan przyciskow
		*/
		void updateButtons();
		/*!
		 * @brief Rysuje przyciski na ekranie
		*/
		void drawButtons();
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

