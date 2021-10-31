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
				al_draw_bitmap(this->block_wall, blocks[i][j].getX(), blocks[i][j].getY(), 0);
				break;
			case BLOCK_TYPE::STONE:
				al_draw_bitmap(this->block_stone, blocks[i][j].getX(), blocks[i][j].getY(), 0);
				break;
			default:
				break;
			}
		}
	}

	al_set_target_bitmap(al_get_backbuffer(al_get_current_display()));
	al_clear_to_color(al_map_rgb(30, 30, 30));
	al_draw_scaled_bitmap(this->main_world, 0, 0, 240, 240, (1280/2) - (720/2), 0, 720, 720, 0);
}

void GameScene::show()
{
	this->main_world = al_create_bitmap(240, 240);

	this->block_floor = al_create_bitmap(20, 20);
	this->block_floor = al_load_bitmap("gfx/floor.png");

	this->block_wall = al_create_bitmap(20, 20);
	this->block_wall = al_load_bitmap("gfx/wall.png");

	this->block_stone = al_create_bitmap(20, 20);
	this->block_stone = al_load_bitmap("gfx/stone.png");

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			
			this->blocks[i][j].setX(i * Block::WIDTH);
			this->blocks[i][j].setY(j * Block::WIDTH);
			if ((i % 2) == 0) {
				this->blocks[i][j].setBlockType(STONE);
			} else {
				this->blocks[i][j].setBlockType(AIR);
			}
		}
	}
}

void GameScene::dispose()
{

}
