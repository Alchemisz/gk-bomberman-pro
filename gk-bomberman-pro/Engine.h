#pragma once
#include "EngineConfiguration.h"
#include <allegro5/allegro.h>
#include <allegro5/timer.h>
class Engine
{
public:
	Engine(EngineConfiguration& config);
private:
	EngineConfiguration config;
	ALLEGRO_DISPLAY* display;
	ALLEGRO_TIMER* loopTimer;
	ALLEGRO_EVENT_QUEUE* eventQueue;
	bool redraw;

	void init();
	void loop();
	void close();
};

