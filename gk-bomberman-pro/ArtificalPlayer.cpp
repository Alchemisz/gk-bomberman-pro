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

	for (int i = 0; i < 12+1; i++) {
		for (int j = 0; j < 12 + 1; j++) {
			markedMap[curBlock.first][curBlock.second] = 0;
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
		markedMap[bombPos.first][bombPos.second] |= BOMB_MASK;
		markedMap[bombPos.first][bombPos.second] |= DANGER_MASK;
		for (direction dir : {LEFT, UP, RIGHT, DOWN}) {
			for (int i = 0; i <= bomb->getPower(); i++) {
				switch (dir) {
				case LEFT:
					if (!(bombPos.first - i <= 0)) {
						markedMap[bombPos.first - i][bombPos.second] |= DANGER_MASK;
					}
					break;
				case UP:
					if (!(bombPos.second - i <= 0)) {
						markedMap[bombPos.first][bombPos.second - i] |= DANGER_MASK;
					}
					break;
				case RIGHT:
					if (!(bombPos.first + i > 12)) {
						markedMap[bombPos.first + i][bombPos.second] |= DANGER_MASK;
					}
					break;
				case DOWN:
					if (!(bombPos.second + i > 12)) {
						markedMap[bombPos.first][bombPos.second + i] |= DANGER_MASK;
					}
					break;
				}
			}
		}
	}
	for (Explosion* bomb : explosionList) {
		std::pair<int, int> bombPos = std::pair<int, int>((int)(bomb->getX() + 7) / Block::WIDTH, (int)(bomb->getY() + 7) / Block::WIDTH);
		markedMap[bombPos.first][bombPos.second] |= DANGER_MASK;
	}

}

std::pair<int, int> ArtificalPlayer::findPath(int destX, int destY)
{
	int visitedMap[12 + 1][12 + 1];
	std::pair<int, int> parents[12 + 1][12 + 1];
	std::priority_queue<std::pair<int, std::pair<int, int>>> queue;
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j++) {
			visitedMap[i][j] = 0;
		}
	}
	std::pair<int, int> curBlock = getBlockIndex();
	if (destX == curBlock.first && destY == curBlock.second) {
		return curBlock;
	}
	std::stack<std::pair<int, int>> path;
	int aprox = 1000 - (abs(curBlock.first - destX) + abs(curBlock.second - destY));
	queue.push(std::pair<int, std::pair<int, int>> (aprox, curBlock));

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
					if ((markedMap[_x][_y] & ACCESIBLE_MASK) != 0) {
						int aprox = 1000 - (abs(_x - destX) + abs(_y - destY));
						parents[_x][_y] = std::pair<int, int>(cur);
						queue.push(std::pair<int, std::pair<int, int>>(aprox, std::pair<int, int>(_x, _y)));
					}
				}
			}
		}
	}

	if (success) {
		std::cout << "success" << std::endl;
		std::pair<int, int> current = std::pair<int, int>(destX, destY);
		while (parents[current.first][current.second].first != curBlock.first && parents[current.first][current.second].second != curBlock.second) {
			int oldX = current.first;
			int oldY = current.second;
			current.first = parents[oldX][oldY].first;
			current.second = parents[oldX][oldY].second;
		}
		return current;
	}
	std::cout << "failure" << std::endl;
	return curBlock;
}

std::pair<int, int> ArtificalPlayer::closestSafe(Block blocks[12 + 1][12 + 1])
{
	return std::pair<int, int>(0, 0);
}



void ArtificalPlayer::logic(Block blocks[12 + 1][12 + 1], std::list<Bomb*> bombList, std::list<Explosion*> explosionList, Player& player)
{
	std::pair<int, int> curBlock = getBlockIndex();
	std::queue<std::pair<int, int>> path;
	markMap(blocks, bombList, explosionList);
	std::pair<int, int> playerBlock = player.getBlockIndex();
	std::pair<int, int> next = findPath(playerBlock.first, playerBlock.second);
	std::cout << "P: " << next.first << " : " << next.second << std::endl;
	if (next.first > curBlock.first) {
		Keyboard::artificialSetDown(playerConfiguration->getMoveRIGHT());
	}
	if (next.first < curBlock.first) {
		Keyboard::artificialSetDown(playerConfiguration->getMoveLEFT());
	}
	if (next.second > curBlock.second) {
		Keyboard::artificialSetDown(playerConfiguration->getMoveDOWN());
	}
	if (next.second < curBlock.second) {
		Keyboard::artificialSetDown(playerConfiguration->getMoveUP());
	}
}
