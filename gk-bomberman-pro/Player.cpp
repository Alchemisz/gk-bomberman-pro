#include "Player.h"
#include "Keyboard.h"

void Player::setX(float x) {
	this->x = x;
}

void Player::setY(float y) {
	this->y = y;
}

void Player::setVelocity(float newVelocity)
{
	this->velocity = newVelocity;
}

float Player::getVelocity()
{
	return this->velocity;
}

float Player::getX() {
	return this->x;
}

float Player::getY() {
	return this->y;
}

bool Player::getIsMoving()
{
	return this->isMoving;
}

void Player::setIsMoving(bool moving)
{
	this->isMoving = moving;
}

direction Player::getPositionState()
{
	return this->state;
}

void Player::setPositionState(direction state)
{
	this->state = state;
}

std::pair<int, int> Player::getBlockIndex()
{
	return std::pair<int, int>(this->x / Block::WIDTH, this->y / Block::WIDTH);
}

void Player::move()
{	

	this->isMoving = false;

	if (Keyboard::isKeyDown(ALLEGRO_KEY_W)) {
		this->y -= this->velocity;
		this->isMoving = true;
		this->state = UP;
	}
	if (Keyboard::isKeyDown(ALLEGRO_KEY_S)) {
		this->y += this->velocity;
		this->isMoving = true;
		this->state = DOWN;
	}
	if (Keyboard::isKeyDown(ALLEGRO_KEY_A)) {
		this->x -= this->velocity;
		this->isMoving = true;
		this->state = LEFT;
	}
	if (Keyboard::isKeyDown(ALLEGRO_KEY_D)) {
		this->x += this->velocity;
		this->isMoving = true;
		this->state = RIGHT;
	}
}

void Player::drawPlayer()
{
	al_draw_filled_rectangle(this->x, this->y, this->x + PLAYER_WIDTH, this->y + PLAYER_WIDTH, al_map_rgb(0, 255, 0));
}

void Player::putBomb()
{
}