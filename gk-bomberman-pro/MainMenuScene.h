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

enum MENU_BUTTONS {SINGLEPLAYER, MULTIPLAYER, HELP, EXIT};

class MainMenuScene : public Scene
{
	private:
		Button* buttons[4];
		ALLEGRO_BITMAP* background;
		ALLEGRO_BITMAP* face;
		ALLEGRO_BITMAP* logo;
		ALLEGRO_BITMAP* ricardo_bomberman;
		AudioManager* Audio;

		PrimitiveAnimation* background_animation;
		void updateButtons();
		void drawButtons();
	public: 
		virtual void render();
		virtual void show();
		virtual void dispose();
};

