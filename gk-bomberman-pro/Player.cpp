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

int Player::getPower()
{
	return this->power;
}

void Player::setPower(int power) {
	this->power = power;
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
	return std::pair<int, int>((this->x + 7.0) / Block::WIDTH, (this->y + 7.0) / Block::WIDTH);
}

PlayerConfiguration* Player::getPlayerConfiguration()
{
	return this->playerConfiguration;
}

void Player::setPlayerConfiguration(PlayerConfiguration* playerConfiguration)
{
	this->playerConfiguration = playerConfiguration;
}

bool Player::getIsArtifical()
{
	return isArtifical;
}

void Player::generateRandomBonus()
{
	srand((int)this + time(NULL));
	bonus_types temp;
	do
	{
		temp = (bonus_types)(rand() % 4 + 1);
	} while (temp == this->bonus_type);

	switch (temp)
	{
	case INVINCIBILITY:
	{
		bonus_invincibility = true;
		bonus_type = INVINCIBILITY;
		break;
	}
	case SPEED:
	{
		this->setVelocity(2);
		bonus_type = SPEED;
		break;
	}
	case BONUS_BOMBS:
	{
		maxBombCredits = 180;
		bonus_type = BONUS_BOMBS;
		break;
	}
	case STRONGER_BOMBS:
	{
		this->setPower(6);
		bonus_type = STRONGER_BOMBS;
		break;
	}
	}
}

void Player::incScore()
{
	score++;
}

void Player::resetBonus()
{
	//bonus_type = NO_BONUS;
	bonus_invincibility = false;
	this->setVelocity(1);
	maxBombCredits = 90;
	this->setPower(3);
}

int Player::getScore()
{
	return score;
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
