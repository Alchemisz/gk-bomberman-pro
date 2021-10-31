#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "SceneManager.h"
#include "DebugScene.h"
#include "Scene.h"
#include "Block.h"
#include <iostream>
#include "MapGenerator.h"

class GameScene : public Scene
{
private:
	ALLEGRO_EVENT_QUEUE* eventQueue;
	Block blocks[12][12];
	ALLEGRO_BITMAP* block_floor;
	ALLEGRO_BITMAP* block_wall;
	ALLEGRO_BITMAP* block_stone;
	ALLEGRO_BITMAP* block_wall_border[4];

	ALLEGRO_BITMAP* main_world;

	MapGenerator MapGen;

public:
	virtual void render();
	virtual void show();
	virtual void dispose();
};
