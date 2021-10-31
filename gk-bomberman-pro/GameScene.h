#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "SceneManager.h"
#include "DebugScene.h"
#include "Scene.h"
#include "Block.h"
#include <iostream>
class GameScene : public Scene
{
private:
	ALLEGRO_EVENT_QUEUE* eventQueue;
	Block blocks[12][12];
	ALLEGRO_BITMAP* block_floor;
	ALLEGRO_BITMAP* block_wall;
	ALLEGRO_BITMAP* block_stone;

	ALLEGRO_BITMAP* main_world;

public:
	virtual void render();
	virtual void show();
	virtual void dispose();
};
