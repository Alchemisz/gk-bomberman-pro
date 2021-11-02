#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "SceneManager.h"
#include "DebugScene.h"
#include "Scene.h"
#include "Keyboard.h"
#include "GameScene.h"
class MainMenuScene : public Scene
{
	private:

	public: 
		virtual void render();
		virtual void show();
		virtual void dispose();
};

