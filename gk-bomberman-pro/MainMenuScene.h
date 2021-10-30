#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "Scene.h"
class MainMenuScene : public Scene
{
	private:
		ALLEGRO_EVENT_QUEUE* eventQueue;
	public: 
		virtual void render();
		virtual void show();
		virtual void dispose();
};

