#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "SceneManager.h"
#include "DebugScene.h"
#include "Scene.h"
#include "Block.h"
#include <iostream>
#include "MapGenerator.h"
#include "PrimitiveAnimation.h"
#include "Keyboard.h"
#include "Player.h"
#include "Bomb.h"
#include "Explosion.h"
#include "Engine.h"
#include "ScoreBox.h"

const int BLOCKS_WIDTH = 12;
const int BLOCKS_HEIGHT = 12;

class GameScene : public Scene
{
private:
	ALLEGRO_TIMER* bombTimer;
	ALLEGRO_EVENT_QUEUE* bombTimerQueue;

	static const int SCALLING_LEVEL = 3;
	const int MAP_WIDTH = 240;
	const int MAP_HEIGHT = 240;

	Block blocks[BLOCKS_WIDTH + 1][BLOCKS_HEIGHT + 1];
	ALLEGRO_BITMAP* block_floor;
	ALLEGRO_BITMAP* block_wall;
	ALLEGRO_BITMAP* block_stone;
	ALLEGRO_BITMAP* block_wall_border[4];
	std::list<Player*> playerList;
	ALLEGRO_BITMAP* main_world;
	ALLEGRO_BITMAP* game_background;

	MapGenerator MapGen;
	PrimitiveAnimation *PlayerAnim;
	PrimitiveAnimation *PlayerAnim2;
	PrimitiveAnimation *BombAnim;
	PrimitiveAnimation* explosionAnimation_up;
	PrimitiveAnimation* explosionAnimation_down;
	PrimitiveAnimation* explosionAnimation_left;
	PrimitiveAnimation* explosionAnimation_right;
	PrimitiveAnimation* explosionAnimation_center;

	ALLEGRO_BITMAP* Player1Icon;
	ALLEGRO_BITMAP* Player2Icon;
	Player player;

	std::list<Bomb*> bombList;
	std::list<Explosion*> explosionList;

	ScoreBox* SBox;

	void playerUpdate(Player& player);
	void bombRender();
	void renderExplosions();
	void updateExplosions();
	void checkCollisions();
	void resetGame();
public:
	virtual void render();
	virtual void show();
	virtual void dispose();
};
