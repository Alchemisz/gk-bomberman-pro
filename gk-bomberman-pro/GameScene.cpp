#include "GameScene.h"

void GameScene::playerUpdate(Player& player)
{
	player.setIsMoving(false);
	float deltaX = player.getX(), deltaY = player.getY();


	//Postawienie bomby
	if (Keyboard::isKeyDown(ALLEGRO_KEY_SPACE)) {
		Block* block = &blocks[player.getBlockIndex().first][player.getBlockIndex().second];
		//Jesli na bloku nie ma bomby
		if (!block->getHasBomb()) {
			Bomb* bomb = new Bomb(player.getPower());
			block->setHasBomb(true);
			bomb->setX(block->getX());
			bomb->setY(block->getY());
			bombList.push_back(bomb);
		}
	}

	

	if (Keyboard::isKeyDown(ALLEGRO_KEY_W)) {
		deltaY = deltaY - player.getVelocity();
		player.setIsMoving(true);
		player.setPositionState(UP);
	}
	if (Keyboard::isKeyDown(ALLEGRO_KEY_S)) {
		deltaY = deltaY + player.getVelocity();
		player.setIsMoving(true);
		player.setPositionState(DOWN);
	}
	if (Keyboard::isKeyDown(ALLEGRO_KEY_A)) {
		deltaX = deltaX - player.getVelocity();
		player.setIsMoving(true);
		player.setPositionState(LEFT);
	}
	if (Keyboard::isKeyDown(ALLEGRO_KEY_D)) {
		deltaX = deltaX + player.getVelocity();
		player.setIsMoving(true);
		player.setPositionState(RIGHT);
	}
	if ((deltaX < 0 || deltaX + 14 > MAP_WIDTH) || (deltaY < 0 || deltaY + 14 > MAP_HEIGHT)) {
		return;
	}

	Block b1 = blocks[(int)((deltaX + 13 + 0.5) / Block::WIDTH)][(int)((deltaY + 13 + 0.5) / Block::WIDTH)];
	Block b2 = blocks[(int)((deltaX + 0.5) / Block::WIDTH)][(int)((deltaY + 0.5) / Block::WIDTH)];

	Block b3,b4;


	

	switch (player.getPositionState())
	{
	case UP:
		{
		if ((int)((player.getY() + 0.5) / Block::WIDTH - 1) < 0)break;
		b3 = blocks[(int)((player.getX() + 0.5) / Block::WIDTH)][(int)((player.getY() + 0.5) / Block::WIDTH - 1)];
		b4 = blocks[(int)((player.getX() + 13 + 0.5) / Block::WIDTH)][(int)((player.getY() + 13 + 0.5) / Block::WIDTH - 1)];
		break;
	}
	case LEFT:
	{
		if ((int)((player.getX() + 0.5) / Block::WIDTH - 1) < 0)break;
		b3 = blocks[(int)((player.getX() + 0.5) / Block::WIDTH - 1)][(int)((player.getY() + 0.5) / Block::WIDTH)];
		b4 = blocks[(int)((player.getX() + 13 + 0.5) / Block::WIDTH - 1)][(int)((player.getY() + 13 + 0.5) / Block::WIDTH)];
		break;
	}
	case RIGHT:
	{
		if ((int)((player.getX() + 0.5) / Block::WIDTH + 1) > 11)break;
		b3 = blocks[(int)((player.getX() + 0.5) / Block::WIDTH + 1)][(int)((player.getY() + 0.5) / Block::WIDTH )];
		b4 = blocks[(int)((player.getX() + 13 + 0.5) / Block::WIDTH + 1)][(int)((player.getY() + 13 + 0.5) / Block::WIDTH)];
		break;
	}
	case DOWN:
	{
		if ((int)((player.getY() + 0.5) / Block::WIDTH - 1) > 11)break;
		b3 = blocks[(int)((player.getX() + 0.5) / Block::WIDTH)][(int)((player.getY() + 0.5) / Block::WIDTH + 1)];
		b4 = blocks[(int)((player.getX() + 13 + 0.5) / Block::WIDTH)][(int)((player.getY() + 13 + 0.5) / Block::WIDTH + 1)];
		break;
	}

	}

	std::pair<int, int> standingBlock = player.getBlockIndex();

	if ((b1.getBlockType() == AIR && (!b1.getHasBomb() || (b1.getX() == standingBlock.first && b1.getY() == standingBlock.second))) 
		&& (b2.getBlockType() == AIR && (!b2.getHasBomb() || (b2.getX() == standingBlock.first && b2.getY() == standingBlock.second)))
		|| ((b1.getBlockType() == AIR && (!b3.getHasBomb() || (b1.getX() == standingBlock.first && b1.getY() == standingBlock.second)))
		&& (b2.getBlockType() == AIR && (!b4.getHasBomb() || (b2.getX() == standingBlock.first && b2.getY() == standingBlock.second)))
			&& (deltaX - player.getX())*(deltaY - player.getY()) == 0)) {
		
		player.setX(deltaX);
		player.setY(deltaY);
	}


}

void GameScene::bombRender()
{
	//Rysowanie bomb
	for (Bomb* bomb : bombList) {
		BombAnim->drawAnimation(bomb->getX() + 3, bomb->getY() + 3, 0);
			//bomb->getX() + 3 + Bomb::BOMB_WIDTH, bomb->getY() + Bomb::BOMB_WIDTH, al_map_rgb(30, 30, 30));
	}
}

void GameScene::renderExplosions()
{
	for (Explosion* explosion :  explosionList) {
		Block bl = blocks[explosion->_x][explosion->_y];
		this->explosionAnimation->drawAnimation(bl.getX(), bl.getY(), 0);
	}
}


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

	//player.drawPlayer();

	//player.move();
	//playerUpdate(player);
	for (Player* player : playerList) {
		playerUpdate(*player);
	}

	ALLEGRO_EVENT ev;
	ev.type = NULL;
	do {
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			for (auto it = bombList.begin(); it != bombList.end();) {
				Bomb* bomb = *it;
				if (bomb->decrementLife()) {
					std::pair<int, int> bombPos = std::pair<int, int>((int)(bomb->getX()+7) / Block::WIDTH, (int)(bomb->getY()+7) / Block::WIDTH);
					std::cout << "center x:" << bombPos.first << " y: " << bombPos.second << std::endl;
					for (direction dir : {LEFT, UP, RIGHT, DOWN}) {
						for (int i = 1; i < bomb->getPower(); i++) {
							int deltaX = 0, deltaY = 0;
							switch (dir) {
							case LEFT:
								deltaX = bombPos.first - i;
								if (deltaX >= 0 && deltaX < BLOCKS_WIDTH) {
									Explosion* exp = new Explosion();
									exp->setDir(dir);
									exp->_x = deltaX;
									exp->_y = bombPos.second;
									explosionList.push_back(exp);
								}
								break;
							case UP:
								deltaY = bombPos.second - i;
								if (deltaY >= 0 && deltaX < BLOCKS_HEIGHT) {
									Explosion* exp = new Explosion();
									exp->setDir(dir);
									exp->_y = deltaY;
									exp->_x = bombPos.first;
									explosionList.push_back(exp);
								}
								break;
							case RIGHT:
								deltaX = bombPos.first + i;
								if (deltaX >= 0 && deltaX < BLOCKS_WIDTH) {
									Explosion* exp = new Explosion();
									exp->setDir(dir);
									exp->_x = deltaX;
									exp->_y = bombPos.second;
									explosionList.push_back(exp);
								}
								break;
							case DOWN:
								deltaY = bombPos.second + i;
								if (deltaY >= 0 && deltaX < BLOCKS_HEIGHT) {
									Explosion* exp = new Explosion();
									exp->setDir(dir);
									exp->_y = deltaY;
									exp->_x = bombPos.first;
									explosionList.push_back(exp);
								}
								break;
							}

						}
					}
					blocks[bombPos.first][bombPos.second].setHasBomb(false);
					it = bombList.erase(it);
					delete bomb;
					
				}
				if (it != bombList.end()) {
					++it;
				}
			}
		}
		ev.type = NULL;
	} while (al_get_next_event(this->bombTimerQueue, &ev) != NULL);

	renderExplosions();

	for (Player* player : playerList) {
		if (player->getX() < 50) {
			if (player->getIsMoving())
				PlayerAnim->drawAnimation(player->getX(), player->getY(), (int)player->getPositionState());
			else PlayerAnim->drawDefaultPosition(player->getX(), player->getY(), (int)player->getPositionState());
		}
		else {
				if (player->getIsMoving())
					PlayerAnim2->drawAnimation(player->getX(), player->getY(), (int)player->getPositionState());
				else PlayerAnim2->drawDefaultPosition(player->getX(), player->getY(), (int)player->getPositionState());
		}
		
	}

	/*if (player.getIsMoving())
		PlayerAnim->drawAnimation(player.getX(), player.getY(), (int)player.getPositionState());
	else PlayerAnim->drawDefaultPosition(player.getX(), player.getY(), (int)player.getPositionState());*/

	bombRender();

	al_set_target_bitmap(al_get_backbuffer(al_get_current_display()));
	al_clear_to_color(al_map_rgb(30, 30, 30));
	al_draw_scaled_bitmap(this->main_world, 0, 0, MAP_WIDTH, MAP_HEIGHT, (1280/2) - (720/2), 0,
							MAP_WIDTH * SCALLING_LEVEL, MAP_HEIGHT * SCALLING_LEVEL, 0);

}

void GameScene::show()
{	
	bombTimerQueue = al_create_event_queue();
	bombTimer = al_create_timer(1.0);
	al_register_event_source(bombTimerQueue, al_get_timer_event_source(bombTimer));
	al_start_timer(bombTimer);

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

	this->PlayerAnim = new PrimitiveAnimation("gfx/plranim.png", 6, 1, 3, 14, 84);
	this->PlayerAnim2 = new PrimitiveAnimation("gfx/plranim.png", 6, 1, 3, 14, 84);
	this->BombAnim = new PrimitiveAnimation("gfx/bomb.png", 5, 1, 2, 14, 70);
	this->explosionAnimation = new PrimitiveAnimation("gfx/exp.png", 5, 1, 3, 20, 100);


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

	Player* pl1 = new Player();
	//Player* pl2 = new Player();
	pl1->setX(0);
	pl1->setY(0);

	//pl2->setX(220);
	//pl2->setY(220);

	this->playerList.push_back(pl1);
	//this->playerList.push_back(pl2);
}

void GameScene::dispose()
{

}
