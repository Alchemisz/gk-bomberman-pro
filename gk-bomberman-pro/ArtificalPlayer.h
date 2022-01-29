#pragma once
#include "Player.h"
#include "Keyboard.h"
#include "Block.h"
#include "Bomb.h"
#include "Explosion.h"
#include <stack>
#include <list>
#include <queue>

const int WALL_MASK = 1;
const int DANGER_MASK = WALL_MASK << 1;
const int BIG_DANGER_MASK = DANGER_MASK << 1;
const int ENEMY_MASK = BIG_DANGER_MASK << 1;
const int AIR_MASK = ENEMY_MASK << 1;
const int BOMB_MASK = AIR_MASK << 1;
const int STONE_MASK = BOMB_MASK << 1;
const int ME_MASK = STONE_MASK << 1;
const int ACCESIBLE_MASK = ME_MASK << 1;


class ArtificalPlayer : public Player
{
private:
	const bool isArtifical = true;
	std::pair<int, int> nextBlock = { 0, 0 };
	bool danger = false;
	int bombCounter = 0;
	int aggressive = true;
	int markedMap[12 + 1][12 + 1];
public:
	virtual bool getIsArtifical();
	void moveLeft();
	std::pair<int, int> closestSafe(Block blocks[12 + 1][12 + 1]);
	void markMap(Block blocks[12 + 1][12 + 1], std::list<Bomb*> bombList, std::list<Explosion*> explosionList);
	std::vector<std::pair<int, int>> findPath(int destX, int destY);
	std::vector<std::pair<int, int>> findBlockedPath(int destX, int destY);
	void logic(Block blocks[12 + 1][12 + 1], std::list<Bomb*>& bombList, std::list<Explosion*>& explosionList, Player& player);
};

