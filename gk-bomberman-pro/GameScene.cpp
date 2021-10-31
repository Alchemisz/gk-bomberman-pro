#include "GameScene.h"

void GameScene::render()
{
	ALLEGRO_BITMAP* backup_world = al_get_target_bitmap();
	al_set_target_bitmap(this->main_world);


	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			switch (blocks[i][j].getBlockType())
			{
			case BLOCK_TYPE::AIR:
				al_draw_bitmap(this->block_floor, blocks[i][j].getX(), blocks[i][j].getY(), 0);
				break;
			case BLOCK_TYPE::WALL:
			{
				al_draw_bitmap(this->block_wall, blocks[i][j].getX(), blocks[i][j].getY(), 0);
				break;
			}
			case BLOCK_TYPE::STONE:
				al_draw_bitmap(this->block_stone, blocks[i][j].getX(), blocks[i][j].getY(), 0);
				break;
			default:
				break;
			}
		}
	}

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (blocks[i][j].getBlockType() == WALL)
			{
				if (i != 11)
					if (blocks[i + 1][j].getBlockType() == AIR)
						al_draw_bitmap(this->block_wall_border[2], blocks[i + 1][j].getX(), blocks[i + 1][j].getY(), 0);
				if (j != 11)
					if (blocks[i][j + 1].getBlockType() == AIR)
						al_draw_bitmap(this->block_wall_border[3], blocks[i][j + 1].getX(), blocks[i][j + 1].getY(), 0);
				if (i != 0)
					if (blocks[i - 1][j].getBlockType() == AIR)
						al_draw_bitmap(this->block_wall_border[0], blocks[i - 1][j].getX(), blocks[i - 1][j].getY(), 0);
				if (j != 0)
					if (blocks[i][j - 1].getBlockType() == AIR)
						al_draw_bitmap(this->block_wall_border[1], blocks[i][j - 1].getX(), blocks[i][j - 1].getY(), 0);
			}
		}
	}

	al_set_target_bitmap(al_get_backbuffer(al_get_current_display()));
	al_clear_to_color(al_map_rgb(30, 30, 30));
	al_draw_scaled_bitmap(this->main_world, 0, 0, 240, 240, (1280/2) - (720/2), 0, 720, 720, 0);



	ALLEGRO_EVENT ev;
	ev.type = NULL;

	do {
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			MapGen.generateMap(this->blocks);
		}
	} while (al_get_next_event(this->eventQueue, &ev) != NULL);
}

void GameScene::show()
{	
	this->eventQueue = al_create_event_queue();
	al_register_event_source(this->eventQueue, al_get_mouse_event_source());
	al_register_event_source(this->eventQueue, al_get_keyboard_event_source());
	al_register_event_source(this->eventQueue, al_get_display_event_source(al_get_current_display()));


	this->main_world = al_create_bitmap(240, 240);

	this->block_floor = al_create_bitmap(20, 20);
	this->block_floor = al_load_bitmap("gfx/floor.png");

	this->block_wall = al_create_bitmap(20, 20);
	this->block_wall = al_load_bitmap("gfx/wall.png");

	this->block_stone = al_create_bitmap(20, 20);
	this->block_stone = al_load_bitmap("gfx/stone.png");

	for (int i = 0; i < 4; i++)this->block_wall_border[i] = al_create_bitmap(20, 20);

	this->block_wall_border[0] = al_load_bitmap("gfx/g_left.png");
	this->block_wall_border[1] = al_load_bitmap("gfx/g_up.png");
	this->block_wall_border[2] = al_load_bitmap("gfx/g_right.png");
	this->block_wall_border[3] = al_load_bitmap("gfx/g_down.png");

	for (int i = 0; i < 4; i++)al_convert_mask_to_alpha(this->block_wall_border[i], al_map_rgb(255, 255, 0));

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			this->blocks[i][j].setBlockType(AIR);

			this->blocks[i][j].setX(i * Block::WIDTH);
			this->blocks[i][j].setY(j * Block::WIDTH);
			
		}
	}

	MapGen.generateMap(this->blocks);
}

void GameScene::dispose()
{
	al_destroy_event_queue(this->eventQueue);

}
