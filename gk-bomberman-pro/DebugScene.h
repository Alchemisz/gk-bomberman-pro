#pragma once
#include "Scene.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "PrimitiveRenderer.h"
#include "LineSegment.h"
#include "Mouse.h"

class DebugScene :
    public Scene
{
private:
	ALLEGRO_EVENT_QUEUE* eventQueue;
	PrimitiveRenderer renderer;
	int i = 10;
public:
	virtual void render();
	virtual void show();
	virtual void dispose();
};

