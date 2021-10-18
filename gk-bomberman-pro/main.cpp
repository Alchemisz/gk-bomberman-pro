#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "Engine.h"

int main()
{
	Engine engine(EngineConfiguration::getDefault());
	engine.init();
	engine.loop();
}