#include "ArtificalPlayer.h"


bool ArtificalPlayer::getIsArtifical()
{
	return isArtifical;
}

void ArtificalPlayer::moveLeft() {
	Keyboard::artificialSetDown(playerConfiguration->getMoveLEFT());
}



void ArtificalPlayer::markMap(Block blocks[12 + 1][12 + 1], std::list<Bomb*> bombList, std::list<Explosion*> explosionList) {
	std::pair<int, int> curBlock = getBlockIndex();
	markedMap[curBlock.first][curBlock.second] |= ME_MASK;

	for (int i = 0; i < 12 + 1; i++) {
		for (int j = 0; j < 12 + 1; j++) {
			markedMap[i][j] = 0;
			switch (blocks[i][j].getBlockType()) {
			case AIR:
				markedMap[i][j] |= AIR_MASK;
				markedMap[i][j] |= ACCESIBLE_MASK;
				break;
			case WALL:
				markedMap[i][j] |= WALL_MASK;
				break;
			case STONE:
				markedMap[i][j] |= STONE_MASK;
				break;
			}
		}
	}

	for (Bomb* bomb : bombList) {
		std::pair<int, int> bombPos = std::pair<int, int>((int)(bomb->getX() + 7) / Block::WIDTH, (int)(bomb->getY() + 7) / Block::WIDTH);
		int dangerMask = bomb->getLife() < 5 ? BIG_DANGER_MASK | DANGER_MASK : DANGER_MASK;
		markedMap[bombPos.first][bombPos.second] |= BOMB_MASK;
		markedMap[bombPos.first][bombPos.second] |= BIG_DANGER_MASK;
		markedMap[bombPos.first][bombPos.second] &= ~ACCESIBLE_MASK;
		markedMap[bombPos.first][bombPos.second] |= dangerMask;

		for (direction dir : {LEFT, UP, RIGHT, DOWN}) {
			for (int i = 0; i <= bomb->getPower(); i++) {
				switch (dir) {
				case LEFT:
					if (!(bombPos.first - i <= 0)) {
						markedMap[bombPos.first - i][bombPos.second] |= dangerMask;
					}
					break;
				case UP:
					if (!(bombPos.second - i <= 0)) {
						markedMap[bombPos.first][bombPos.second - i] |= dangerMask;
					}
					break;
				case RIGHT:
					if (!(bombPos.first + i > 12)) {
						markedMap[bombPos.first + i][bombPos.second] |= dangerMask;
					}
					break;
				case DOWN:
					if (!(bombPos.second + i > 12)) {
						markedMap[bombPos.first][bombPos.second + i] |= dangerMask;
					}
					break;
				}
			}
		}
	}
	for (Explosion* bomb : explosionList) {
		markedMap[bomb->_x][bomb->_y] |= BIG_DANGER_MASK;
	}

}

#include "PrimitiveRenderer.h"

std::vector<std::pair<int, int>> ArtificalPlayer::findPath(int destX, int destY)
{
	int visitedMap[12 + 1][12 + 1];
	int costMap[12 + 1][12 + 1];
	std::pair<int, int> parents[12 + 1][12 + 1];
	std::priority_queue<std::pair<int, std::pair<int, int>>> queue;
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j++) {
			visitedMap[i][j] = 0;
			costMap[i][j] = 2000;
		}
	}
	std::pair<int, int> curBlock = getBlockIndex();
	if (destX == curBlock.first && destY == curBlock.second) {
		return std::vector<std::pair<int, int>>();
	}
	std::stack<std::pair<int, int>> path;
	costMap[curBlock.first][curBlock.second] = 0;
	int firstAprox = 1000 - (abs(curBlock.first - destX) + abs(curBlock.second - destY));
	queue.push(std::pair<int, std::pair<int, int>>(firstAprox, curBlock));

	int pathLen = 0;
	bool success = false;

	while (!queue.empty()) {
		std::pair<int, std::pair<int, int>> curPoint = queue.top();
		std::pair<int, int> cur = curPoint.second;
		if (cur.first == destX && cur.second == destY) {
			success = true;
			break;
		}
		path.push(cur);
		queue.pop();
		visitedMap[cur.first][cur.second] = 1;

		int neighbours[8] = {
			0, 1,
			-1, 0,
			0, -1,
			1, 0,
		};
		for (int i = 0; i < 8; i += 2) {
			int _x = cur.first + neighbours[i];
			int _y = cur.second + neighbours[i + 1];
			if (_x >= 0 && _x < 12 && _y >= 0 && _y < 12) {
				if (visitedMap[_x][_y] == 0) {
					if ((markedMap[_x][_y] & ACCESIBLE_MASK) != 0 && (markedMap[_x][_y] & BIG_DANGER_MASK) == 0) {
						int tempCost = costMap[cur.first][cur.second] + 1;
						if (markedMap[_x][_y] & DANGER_MASK) {
							tempCost += 25;
						}
						if (tempCost < costMap[_x][_y]) {
							parents[_x][_y] = std::pair<int, int>(cur);
							costMap[_x][_y] = tempCost;
							int aprox = 1000 - ((abs(_x - destX) + abs(_y - destY)) * 2 + costMap[_x][_y]);
							queue.push(std::pair<int, std::pair<int, int>>(aprox, std::pair<int, int>(_x, _y)));
						}
						int a = 2;
					}
				}
			}
		}
	}

	PrimitiveRenderer rend;
	if (success) {
		std::vector<std::pair<int, int>> path;
		std::pair<int, int> current = std::pair<int, int>(destX, destY);
		while (parents[current.first][current.second].first != curBlock.first || parents[current.first][current.second].second != curBlock.second) {

			int oldX = current.first;
			int oldY = current.second;
			int tempX = oldX * 20;
			int tempY = oldY * 20;
			path.push_back(std::pair<int, int>(current.first, current.second));

			//rend.rectangle(Point2D(tempX, tempY), Point2D(tempX + 20, tempY + 20), al_map_rgb(255, 255, 0), false);
			current.first = parents[oldX][oldY].first;
			current.second = parents[oldX][oldY].second;
			//rend.rectangle(Point2D(tempX + 10, tempY + 10), Point2D(current.first * 20 + 10, current.second * 20 + 10), al_map_rgb(255, 255, 0), false);
		}
		int tempX = current.first * 20;
		int tempY = current.second * 20;
		path.push_back(std::pair<int, int>(current.first, current.second));

		//rend.rectangle(Point2D(tempX, tempY), Point2D(tempX + 20, tempY + 20), al_map_rgb(255, 255, 0), false);
		return path;
	}
	return std::vector<std::pair<int, int>>();
}

std::vector<std::pair<int, int>> ArtificalPlayer::findBlockedPath(int destX, int destY)
{
	int visitedMap[12 + 1][12 + 1];
	int costMap[12 + 1][12 + 1];
	std::pair<int, int> parents[12 + 1][12 + 1];
	std::priority_queue<std::pair<int, std::pair<int, int>>> queue;
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j++) {
			visitedMap[i][j] = 0;
			costMap[i][j] = 2000;
		}
	}
	std::pair<int, int> curBlock = getBlockIndex();
	if (destX == curBlock.first && destY == curBlock.second) {
		return std::vector<std::pair<int, int>>();
	}
	std::stack<std::pair<int, int>> path;
	costMap[curBlock.first][curBlock.second] = 0;
	int firstAprox = 1000 - (abs(curBlock.first - destX) + abs(curBlock.second - destY));
	queue.push(std::pair<int, std::pair<int, int>>(firstAprox, curBlock));

	int pathLen = 0;
	bool success = false;

	while (!queue.empty()) {
		std::pair<int, std::pair<int, int>> curPoint = queue.top();
		std::pair<int, int> cur = curPoint.second;
		if (cur.first == destX && cur.second == destY) {
			success = true;
			break;
		}
		path.push(cur);
		queue.pop();
		visitedMap[cur.first][cur.second] = 1;

		int neighbours[8] = {
			0, 1,
			-1, 0,
			0, -1,
			1, 0,
		};
		for (int i = 0; i < 8; i += 2) {
			int _x = cur.first + neighbours[i];
			int _y = cur.second + neighbours[i + 1];
			if (_x >= 0 && _x < 12 && _y >= 0 && _y < 12) {
				if (visitedMap[_x][_y] == 0) {
					if ((markedMap[_x][_y] & STONE_MASK) == 0 && (markedMap[_x][_y] & BIG_DANGER_MASK) == 0) {
						int tempCost = costMap[cur.first][cur.second] + 1;
						if (markedMap[_x][_y] & DANGER_MASK) {
							tempCost += 25;
						}
						if (markedMap[_x][_y] & WALL_MASK) {
							tempCost += 150;
						}
						if (tempCost < costMap[_x][_y]) {
							parents[_x][_y] = std::pair<int, int>(cur);
							costMap[_x][_y] = tempCost;
							int aprox = 1000 - ((abs(_x - destX) + abs(_y - destY)) * 2 + costMap[_x][_y]);
							queue.push(std::pair<int, std::pair<int, int>>(aprox, std::pair<int, int>(_x, _y)));
						}
						int a = 2;
					}
				}
			}
		}
	}

	if (success) {
		std::vector<std::pair<int, int>> path;
		std::pair<int, int> current = std::pair<int, int>(destX, destY);
		while (parents[current.first][current.second].first != curBlock.first || parents[current.first][current.second].second != curBlock.second) {

			int oldX = current.first;
			int oldY = current.second;
			int tempX = oldX * 20;
			int tempY = oldY * 20;
			path.push_back(std::pair<int, int>(current.first, current.second));

			current.first = parents[oldX][oldY].first;
			current.second = parents[oldX][oldY].second;
		}
		int tempX = current.first * 20;
		int tempY = current.second * 20;
		path.push_back(std::pair<int, int>(current.first, current.second));

		return path;
	}
	return std::vector<std::pair<int, int>>();
}

std::pair<int, int> ArtificalPlayer::closestSafe(Block blocks[12 + 1][12 + 1])
{
	int visitedMap[12 + 1][12 + 1];
	std::priority_queue<std::pair<int, std::pair<int, int>>> queue;;
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j++) {
			visitedMap[i][j] = 0;
		}
	}
	std::pair<int, int> curBlock = getBlockIndex();

	queue.push(std::pair<int, std::pair<int, int>>(1000, curBlock));

	while (!queue.empty()) {
		std::pair<int, std::pair<int, int>> curPoint = queue.top();
		int level = curPoint.first - 1;
		std::pair<int, int> cur = curPoint.second;
		if (!(markedMap[cur.first][cur.second] & BIG_DANGER_MASK)) {
			curBlock = std::pair<int, int>(cur.first, cur.second);
			break;
		}
		queue.pop();
		visitedMap[cur.first][cur.second] = 1;

		int neighbours[8] = {
			0, 1,
			1, 0,
			0, -1,
			-1, 0,
		};
		for (int i = 0; i < 8; i += 2) {
			int _x = cur.first + neighbours[i];
			int _y = cur.second + neighbours[i + 1];
			if (_x >= 0 && _x < 12 && _y >= 0 && _y < 12) {
				if (visitedMap[_x][_y] == 0) {
					if ((markedMap[_x][_y] & ACCESIBLE_MASK) != 0) {
						queue.push(std::pair<int, std::pair<int, int>>(level, std::pair<int, int>(_x, _y)));
					}
				}
			}
		}
	}
	return curBlock;
}



void ArtificalPlayer::logic(Block blocks[12 + 1][12 + 1], std::list<Bomb*>& bombList, std::list<Explosion*>& explosionList, Player& player)
{
	std::pair<int, int> curBlock = getBlockIndex();
	markMap(blocks, bombList, explosionList);
	std::pair<int, int> playerBlock = player.getBlockIndex();

	std::pair<int, int> closestSafe = this->closestSafe(blocks);
	std::vector<std::pair<int, int>> path;
	std::pair<int, int> next = curBlock;


	if (closestSafe.first != curBlock.first || closestSafe.second != curBlock.second) {
		path = findPath(closestSafe.first, closestSafe.second);
		if (path.empty()) {

		}
		else {
			next = path.back();
		}
	}
	else {
		if ((abs(playerBlock.first - curBlock.first) + abs(playerBlock.second - curBlock.second)) > 5) {
			path = findPath(playerBlock.first, playerBlock.second);
			if (path.empty()) {
				path = findBlockedPath(playerBlock.first, playerBlock.second);
				if (!path.empty()) {
					std::pair<int, int> nextBlock = path.back();

					if (markedMap[nextBlock.first][nextBlock.second] & WALL_MASK) {
						Block* block = &blocks[curBlock.first][curBlock.second];
						if (!block->getHasBomb() && bombCounter == 0) {
							bombCounter = 210;
							Bomb* bomb = new Bomb(player.getPower());
							block->setHasBomb(true);
							bomb->setX(block->getX());
							bomb->setY(block->getY());
							bombList.push_back(bomb);
						}
						if (bombCounter > 0) {
							bombCounter--;
						}
					}
					else {
						next = nextBlock;
					}
				}
			}
			else {
				next = path.back();
			}
		}
		else {
			int killSpots[8] = {
			0, 2,
			-2, 0,
			0, -2,
			2, 0,
			};

			for (int i = 0; i < 8; i += 2) {
				int _x = playerBlock.first + killSpots[i];
				int _y = playerBlock.second + killSpots[i + 1];

				if (curBlock.first == _x && curBlock.second == _y) {
					Block* block = &blocks[curBlock.first][curBlock.second];
					if (!block->getHasBomb() && bombCounter == 0) {
						bombCounter = 210;
						Bomb* bomb = new Bomb(player.getPower());
						block->setHasBomb(true);
						bomb->setX(block->getX());
						bomb->setY(block->getY());
						bombList.push_back(bomb);
					}
					if (bombCounter > 0) {
						bombCounter--;
					}
				}

				int tempLen = 0;
				if (_x >= 0 && _x < 12 && _y >= 0 && _y < 12 && markedMap[_x][_y] & ACCESIBLE_MASK && (markedMap[_x][_y] & BOMB_MASK) == 0) {
					path = findPath(_x, _y);
					if (path.empty()) {
						path = findBlockedPath(_x, _y);
						if (!path.empty()) {
							std::pair<int, int> nextBlock = path.back();

							if (markedMap[nextBlock.first][nextBlock.second] & WALL_MASK) {
								Block* block = &blocks[curBlock.first][curBlock.second];
								if (!block->getHasBomb() && bombCounter == 0) {
									bombCounter = 210;
									Bomb* bomb = new Bomb(player.getPower());
									block->setHasBomb(true);
									bomb->setX(block->getX());
									bomb->setY(block->getY());
									bombList.push_back(bomb);
								}
								if (bombCounter > 0) {
									bombCounter--;
								}
							}
							else {
								next = nextBlock;
							}
						}
					}
					else {
						next = path.back();
					}
				}
			}


		}
	}

	float realX = this->getX();
	float realY = this->getY();
	float nextX = next.first * 20.0 + 7.0;
	float nextY = next.second * 20.0 + 7.0;


	if (nextX > realX) {
		if (abs(nextX - realX) < this->getVelocity()) {
			this->setX(nextX);
		}
		else {
			this->setX(realX + this->getVelocity());
		}
	}
	if (nextX < realX) {
		if (abs(nextX - realX) < this->getVelocity()) {
			this->setX(nextX);
		}
		else {
			this->setX(realX - this->getVelocity());
		}
	}
	if (nextY > realY) {
		if (abs(nextY - realY) < this->getVelocity()) {
			this->setY(nextY);
		}
		else {
			this->setY(realY + this->getVelocity());
		}
	}
	if (nextY < realY) {
		if (abs(nextY - realY) < this->getVelocity()) {
			this->setY(nextY);
		}
		else {
			this->setY(realY - this->getVelocity());
		}
	}
}
