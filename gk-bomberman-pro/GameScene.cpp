#include "GameScene.h"

void GameScene::DrawCurrentBonus(int x, int y, Player* player)
{	
	float divided_time = (float)BonusFrameTimer / (float)BonusFrameTimerBoundry;
	al_draw_filled_rectangle(x, y, x + 120, y + 120, al_map_rgb(30, 30, 30));
	al_draw_rectangle(x, y, x + 120, y + 120, al_map_rgb(70, 70, 70),5);
	al_draw_filled_rectangle(x + 5, y + divided_time * 115, x + 120 - 5, y + 120 - 5, al_map_rgb_f(divided_time,1-divided_time,0));
	switch (player->bonus_type)
	{
	case INVINCIBILITY:
	{
		al_draw_bitmap(bonus_inv, x + 10, y + 10, 0);
		break;
	}
	case SPEED:
	{
		al_draw_bitmap(bonus_speed, x + 10, y + 10, 0);
		break;
	}
	case BONUS_BOMBS:
	{
		al_draw_bitmap(bonus_bomb, x + 10, y + 10, 0);
		break;
	}
	case STRONGER_BOMBS:
	{
		al_draw_bitmap(bonus_nuke, x + 10, y + 10, 0);
		break;
	}
	default:
	{
		al_draw_bitmap(bonus_null, x + 10, y + 10, 0);
		break;
	}
	}
}

void GameScene::BonusHandler()
{
	BonusFrameTimer = (BonusFrameTimer <= BonusFrameTimerBoundry) ? (BonusFrameTimer + 1) : (0);

	if (BonusFrameTimer != BonusFrameTimerBoundry) return;

	for (Player* player : playerList)
	{
		player->resetBonus();
		player->generateRandomBonus();
	}
}

void GameScene::playerUpdate(Player& player)
{
	player.bombCredits = (player.bombCredits < player.maxBombCredits) ? (player.bombCredits+1) : (player.maxBombCredits);
	player.setIsMoving(false);
	float deltaX = player.getX(), deltaY = player.getY();

	//Konfiguracja gracza
	PlayerConfiguration* playerConfiguration = player.getPlayerConfiguration();

	//Postawienie bomby
	if (Keyboard::isKeyDown(playerConfiguration->getPutBomb())) {
		Block* block = &blocks[player.getBlockIndex().first][player.getBlockIndex().second];
		//Jesli na bloku nie ma bomby
		if (!block->getHasBomb() && (player.bombCredits - player.bombCreditsCost >= 0)) {
			player.bombCredits -= player.bombCreditsCost;
			Bomb* bomb = new Bomb(player.getPower());
			block->setHasBomb(true);
			bomb->setX(block->getX());
			bomb->setY(block->getY());
			bombList.push_back(bomb);
		}
	}

	if (Keyboard::isKeyDown(playerConfiguration->getMoveUP())) {
		deltaY = deltaY - player.getVelocity();
		player.setIsMoving(true);
		player.setPositionState(UP);
	}
	if (Keyboard::isKeyDown(playerConfiguration->getMoveDOWN())) {
		deltaY = deltaY + player.getVelocity();
		player.setIsMoving(true);
		player.setPositionState(DOWN);
	}
	if (Keyboard::isKeyDown(playerConfiguration->getMoveLEFT())) {
		deltaX = deltaX - player.getVelocity();
		player.setIsMoving(true);
		player.setPositionState(LEFT);
	}
	if (Keyboard::isKeyDown(playerConfiguration->getMoveRIGHT())) {
		deltaX = deltaX + player.getVelocity();
		player.setIsMoving(true);
		player.setPositionState(RIGHT);
	}
	if ((deltaX < 0 || deltaX + 14 > MAP_WIDTH) || (deltaY < 0 || deltaY + 14 > MAP_HEIGHT)) {
		return;
	}

	Block b1 = blocks[(int)((deltaX + 13 + 0.5) / Block::WIDTH)][(int)((deltaY + 13 + 0.5) / Block::WIDTH)];
	Block b2 = blocks[(int)((deltaX + 0.5) / Block::WIDTH)][(int)((deltaY + 0.5) / Block::WIDTH)];
	Block b5 = blocks[(int)((deltaX + 13 + 0.5) / Block::WIDTH)][(int)((deltaY + 0.5) / Block::WIDTH)];
	Block b6 = blocks[(int)((deltaX + 0.5) / Block::WIDTH)][(int)((deltaY + 13 + 0.5) / Block::WIDTH)];
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
		&& (b5.getBlockType() == AIR && (!b5.getHasBomb() || (b5.getX() == standingBlock.first && b5.getY() == standingBlock.second)))
		&& (b6.getBlockType() == AIR && (!b6.getHasBomb() || (b6.getX() == standingBlock.first && b6.getY() == standingBlock.second)))

		|| ((b1.getBlockType() == AIR && (!b3.getHasBomb() || (b1.getX() == standingBlock.first && b1.getY() == standingBlock.second)))
		&& (b2.getBlockType() == AIR && (!b4.getHasBomb() || (b2.getX() == standingBlock.first && b2.getY() == standingBlock.second)))
		&& (b5.getBlockType() == AIR && (!b3.getHasBomb() || (b5.getX() == standingBlock.first && b5.getY() == standingBlock.second)))
		&& (b6.getBlockType() == AIR && (!b4.getHasBomb() || (b6.getX() == standingBlock.first && b6.getY() == standingBlock.second)))
			&& (deltaX - player.getX())*(deltaY - player.getY()) == 0)) 
	{
		
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
		switch (explosion->getDir())
		{	
		case UP:
			this->explosionAnimation_up->drawAnimation(bl.getX(), bl.getY(), 0);
			break;
		case DOWN:
			this->explosionAnimation_down->drawAnimation(bl.getX(), bl.getY(), 0);
			break;
		case LEFT:
			this->explosionAnimation_left->drawAnimation(bl.getX(), bl.getY(), 0);
			break;
		case RIGHT:
			this->explosionAnimation_left->drawAnimation(bl.getX(), bl.getY(), 0);
			break;
		case CENTER:
			this->explosionAnimation_center->drawAnimation(bl.getX(), bl.getY(), 0);
			break;
		}
	}
}

void GameScene::updateExplosions()
{
	for (auto it = explosionList.begin(); it != explosionList.end();) {
		Explosion* expl = *it;
		if (expl->decreaseLife()) {
			it = explosionList.erase(it);
			delete expl;
		}
		if (it != explosionList.end()) {
			++it;
		}
	}
}

void GameScene::checkCollisions()
{
	for (Explosion* explo : explosionList) {
		for (Player* player : playerList) {
			std::pair<int, int> standingBlock = player->getBlockIndex();
			if (explo->_x == standingBlock.first && explo->_y == standingBlock.second) {
				
				if (player->bonus_invincibility)continue; // BONUS NIEZNISZCZALNOSC

				for (Player* player2 : playerList) {
					if (player2 != player)player2->incScore();
				}//kazdy gracz ktory nie jest tym co dostal w miche dostaje punkty
				// w sumie moze zostac do trybu 4 graczy bo wtedy najwiecej pkt dostaje ten co przezyje najdluzej

				resetGame();
				return;
			}
		}
	}
}

void GameScene::resetGame()
{
	int positions[8] = { 0,0,220, 220, 20, 220, 220, 20 };
	int idx = 0;
	for (Player* player : playerList) {
		player->setX(positions[idx]);
		player->setY(positions[idx + 1]);
		idx += 2;
	}
	for (Explosion* explo : explosionList)
		delete explo;
	explosionList.clear();

	for (Bomb* b : bombList)
		delete b;
	
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 12; j++)
			blocks[i][j].setHasBomb(false);

	bombList.clear();
	Audio->Play("boom");
	SBox->setActive();

	MapGen.generateMap(this->blocks);
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
	BonusHandler();

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
					Audio->Play("explosion");
					//dodaje centrum wybuchu jak cos
					Explosion* exp_center = new Explosion();
					exp_center->setDir(CENTER);
					exp_center->_x = bombPos.first;
					exp_center->_y = bombPos.second;
					explosionList.push_back(exp_center);

					for (direction dir : {LEFT, UP, RIGHT, DOWN}) {
						bool broke = false;
						for (int i = 1; i < bomb->getPower(); i++) {
							int deltaX = 0, deltaY = 0;
							switch (dir) {
							case LEFT:
								deltaX = bombPos.first - i;
								if (deltaX >= 0 && deltaX < BLOCKS_WIDTH) {
									if (blocks[deltaX][bombPos.second].getBlockType() == AIR) {
										Explosion* exp = new Explosion();
										exp->setDir(dir);
										exp->_x = deltaX;
										exp->_y = bombPos.second;
										explosionList.push_back(exp);
										
									} else if (blocks[deltaX][bombPos.second].getBlockType() == WALL) {
										Explosion* exp = new Explosion();
										exp->setDir(dir);
										exp->_x = deltaX;
										exp->_y = bombPos.second;
										explosionList.push_back(exp);
										broke = true;
										blocks[deltaX][bombPos.second].setBlockType(AIR);
									}
									else if (blocks[deltaX][bombPos.second].getBlockType() == STONE) {
										broke = true;
									}
								}
								break;
							case UP:
								deltaY = bombPos.second - i;
								if (deltaY >= 0 && deltaY < BLOCKS_HEIGHT) {
									if (blocks[bombPos.first][deltaY].getBlockType() == AIR) {
										Explosion* exp = new Explosion();
										exp->setDir(dir);
										exp->_y = deltaY;
										exp->_x = bombPos.first;
										explosionList.push_back(exp);
									}
								else if (blocks[bombPos.first][deltaY].getBlockType() == WALL) {
										Explosion* exp = new Explosion();
										exp->setDir(dir);
										exp->_y = deltaY;
										exp->_x = bombPos.first;
										explosionList.push_back(exp);
										broke = true;
										blocks[bombPos.first][deltaY].setBlockType(AIR);
									}
									else if (blocks[bombPos.first][deltaY].getBlockType() == STONE) {
										broke = true;
									}
								}
								break;
							case RIGHT:
								deltaX = bombPos.first + i;
								if (deltaX >= 0 && deltaX < BLOCKS_WIDTH) {
									if (blocks[deltaX][bombPos.second].getBlockType() == AIR) {
										Explosion* exp = new Explosion();
										exp->setDir(dir);
										exp->_x = deltaX;
										exp->_y = bombPos.second;
										explosionList.push_back(exp);
									}
									else if (blocks[deltaX][bombPos.second].getBlockType() == WALL) {
										Explosion* exp = new Explosion();
										exp->setDir(dir);
										exp->_x = deltaX;
										exp->_y = bombPos.second;
										explosionList.push_back(exp);
										broke = true;
										blocks[deltaX][bombPos.second].setBlockType(AIR);
									}
									else if (blocks[deltaX][bombPos.second].getBlockType() == STONE) {
										broke = true;
									}
								}
								break;
							case DOWN:
								deltaY = bombPos.second + i;
								if (deltaY >= 0 && deltaY < BLOCKS_HEIGHT) {
									if (blocks[bombPos.first][deltaY].getBlockType() == AIR) {
										Explosion* exp = new Explosion();
										exp->setDir(dir);
										exp->_y = deltaY;
										exp->_x = bombPos.first;
										explosionList.push_back(exp);
									}
									else if (blocks[bombPos.first][deltaY].getBlockType() == WALL) {
										Explosion* exp = new Explosion();
										exp->setDir(dir);
										exp->_y = deltaY;
										exp->_x = bombPos.first;
										explosionList.push_back(exp);
										broke = true;
										blocks[bombPos.first][deltaY].setBlockType(AIR);
									}
									else if (blocks[bombPos.first][deltaY].getBlockType() == STONE) {
										broke = true;
									}
								}
								break;
							}
							if (broke) {
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

	updateExplosions();

	checkCollisions();

	renderExplosions();

	for (Player* player : playerList) {
			if (player->getIsMoving())
				player->getPlayerConfiguration()->getAnimation()->drawAnimation(player->getX(), player->getY(), (int)player->getPositionState());
			else 
				player->getPlayerConfiguration()->getAnimation()->drawDefaultPosition(player->getX(), player->getY(), (int)player->getPositionState());

			float divided_time = (float)BonusFrameTimer / (float)BonusFrameTimerBoundry;

			if (player->bonus_invincibility)al_draw_tinted_bitmap(player_shield, al_map_rgb((unsigned char)(rand() * divided_time * 100) % 127 + 127, (unsigned char)(rand() * divided_time * 100) % 127 + 127, (unsigned char)(rand() * divided_time * 100) % 127 + 127), player->getX(), player->getY(), 0);
	}

	/*if (player.getIsMoving())
		PlayerAnim->drawAnimation(player.getX(), player.getY(), (int)player.getPositionState());
	else PlayerAnim->drawDefaultPosition(player.getX(), player.getY(), (int)player.getPositionState());*/

	bombRender();

	al_set_target_bitmap(al_get_backbuffer(al_get_current_display()));
	al_clear_to_color(al_map_rgb(30, 30, 30));
	al_draw_scaled_bitmap(this->main_world, 0, 0, MAP_WIDTH, MAP_HEIGHT, (1280/2) - (720/2), 0,
							MAP_WIDTH * SCALLING_LEVEL, MAP_HEIGHT * SCALLING_LEVEL, 0);

	al_draw_bitmap(game_background, 0, 0, 0);
	//Ohydnie recznie robione, potem trzeba bedzie dorobic to do postaci i dac automatycznie
	al_draw_bitmap(Player1Icon, 20, 20, 0);
	if((playerList.front()->bombCredits - playerList.front()->bombCreditsCost >= 0))
		al_draw_text(Engine::getInstance()->getFont(), al_map_rgb(255, 255, 255), 100, 50, ALLEGRO_ALIGN_LEFT, "Player 1");
	else 
		al_draw_text(Engine::getInstance()->getFont(), al_map_rgb(255, 0, 0), 100, 50, ALLEGRO_ALIGN_LEFT, "Player 1");

	al_draw_bitmap(Player2Icon, 1280 - 20 - 70, 720 - 20 - 70, 0);

	if ((playerList.back()->bombCredits - playerList.back()->bombCreditsCost >= 0))
		al_draw_text(Engine::getInstance()->getFont(), al_map_rgb(255, 255, 255), 1280 -20 - 10 - 70, 720 - 55 , ALLEGRO_ALIGN_RIGHT, "Player 2");
	else
		al_draw_text(Engine::getInstance()->getFont(), al_map_rgb(255, 0, 0), 1280 - 20 - 10 - 70, 720 - 55, ALLEGRO_ALIGN_RIGHT, "Player 2");

	DrawCurrentBonus(20,120,playerList.front());
	DrawCurrentBonus(1280 - 20 - 120, 720 - 20 - 120 - 100, playerList.back());

	//Dla dwoch graczy ten tryb, wiec nie kombinowalem z pozyskaniem wyniku z listy (chodzi o back i front)
	SBox->update(this->Player1Icon,this->Player2Icon,playerList.front()->getScore(), playerList.back()->getScore());
}

void GameScene::show()
{	
	bombTimerQueue = al_create_event_queue();
	bombTimer = al_create_timer(1.0/4);
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
	this->PlayerAnim2 = new PrimitiveAnimation("gfx/plr2anim.png", 6, 1, 3, 14, 84);
	this->BombAnim = new PrimitiveAnimation("gfx/bomb.png", 5, 1, 2, 14, 70);
	this->explosionAnimation_up = new PrimitiveAnimation("gfx/exp_up.png", 5, 1, 3, 20, 100);
	this->explosionAnimation_down = new PrimitiveAnimation("gfx/exp_down.png", 5, 1, 3, 20, 100);
	this->explosionAnimation_left = new PrimitiveAnimation("gfx/exp_left.png", 5, 1, 3, 20, 100);
	this->explosionAnimation_right = new PrimitiveAnimation("gfx/exp_right.png", 5, 1, 3, 20, 100);
	this->explosionAnimation_center = new PrimitiveAnimation("gfx/exp_center.png", 5, 1, 3, 20, 100);


	this->Player1Icon = al_create_bitmap(70, 70);
	this->Player1Icon = al_load_bitmap("gfx/plr1face.png");

	this->Player2Icon = al_create_bitmap(70, 70);
	this->Player2Icon = al_load_bitmap("gfx/plr2face.png");
	this->player_shield = al_load_bitmap("gfx/plrshield.png");
	this->game_background = al_load_bitmap("gfx/backgr.png");
	this->bonus_bomb = al_load_bitmap("gfx/bonus_bomb.png");
	this->bonus_speed = al_load_bitmap("gfx/bonus_speed.png");
	this->bonus_nuke = al_load_bitmap("gfx/bonus_nuke.png");
	this->bonus_inv = al_load_bitmap("gfx/bonus_inv.png");
	this->bonus_null = al_load_bitmap("gfx/bonus_null.png");

	al_convert_mask_to_alpha(this->game_background, al_map_rgb(255, 255, 0));
	al_convert_mask_to_alpha(this->player_shield, al_map_rgb(255, 255, 0));

	SBox = new ScoreBox();
	Audio = new AudioManager();
	Audio->Play("music");
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
	Player* pl2 = new Player();
	pl1->setX(0);
	pl1->setY(0);

	pl2->setX(220);
	pl2->setY(220);

	pl1->setPlayerConfiguration(new PlayerConfiguration(ALLEGRO_KEY_W, ALLEGRO_KEY_S, ALLEGRO_KEY_A, ALLEGRO_KEY_D, ALLEGRO_KEY_Q, this->PlayerAnim));
	pl2->setPlayerConfiguration(new PlayerConfiguration(ALLEGRO_KEY_UP, ALLEGRO_KEY_DOWN, ALLEGRO_KEY_LEFT, ALLEGRO_KEY_RIGHT, ALLEGRO_KEY_SPACE, this->PlayerAnim2));

	this->playerList.push_back(pl1);
	this->playerList.push_back(pl2);
}

void GameScene::dispose()
{

}
