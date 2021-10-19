#pragma once
#include "EngineConfiguration.h"
#include <allegro5/allegro.h>
#include <allegro5/timer.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <string>

class Engine
{
public:
	void clearScreen(ALLEGRO_COLOR color);
	void errorMessage(std::string title, std::string heading, std::string errorMsg);
	void init();
	void loop();
	void close();
	static Engine* getInstance();
	static Engine* engine;
	Engine(EngineConfiguration config);
protected:
private:
	EngineConfiguration config;
	ALLEGRO_DISPLAY* display;
	ALLEGRO_TIMER* loopTimer;
	ALLEGRO_EVENT_QUEUE* eventQueue;
	ALLEGRO_EVENT_QUEUE* loopQueue;
};








