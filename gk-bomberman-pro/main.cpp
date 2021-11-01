#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "Engine.h"
#include "SceneManager.h"
#include "MainMenuScene.h"

int main()
{
	Engine* engine = Engine::getInstance();
	engine->init();
	engine->loop();
}