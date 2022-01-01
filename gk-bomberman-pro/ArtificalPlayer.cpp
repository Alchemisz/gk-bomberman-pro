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

#include "PrimitiveRenderer.h"

std::pair<int, int> ArtificalPlayer::findPath(int destX, int destY)
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
		return curBlock;
	}
	std::stack<std::pair<int, int>> path;
	costMap[curBlock.first][curBlock.second] = 0;
	int firstAprox = 1000 - (abs(curBlock.first - destX) + abs(curBlock.second - destY));
	queue.push(std::pair<int, std::pair<int, int>> (firstAprox, curBlock));

	int pathLen = 0;
	bool success = false;
	int idx = 0;

	while (!queue.empty()) {
		idx++;
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
						int tempCost = costMap[cur.first][cur.second] + 1;
						if (markedMap[_x][_y] & DANGER_MASK) {
							tempCost += 20;
						}
						if (tempCost < costMap[_x][_y]) {
							parents[_x][_y] = std::pair<int, int>(cur);
							costMap[_x][_y] = tempCost;
							int aprox = 1000 - (abs(_x - destX) + abs(_y - destY) + costMap[_x][_y]);
							queue.push(std::pair<int, std::pair<int, int>>(aprox, std::pair<int, int>(_x, _y)));
						}
						//parents[_x][_y] = std::pair<int, int>(cur);
						int a = 2;
					}
				}
			}
		}
	}

	PrimitiveRenderer rend;
	if (success) {
		std::pair<int, int> current = std::pair<int, int>(destX, destY);
		while (parents[current.first][current.second].first != curBlock.first || parents[current.first][current.second].second != curBlock.second) {
			
			int oldX = current.first;
			int oldY = current.second;
			int tempX = oldX * 20;
			int tempY = oldY * 20;
			rend.rectangle(Point2D(tempX, tempY), Point2D(tempX+20, tempY+20), al_map_rgb(255, 255, 0), false);

			current.first = parents[oldX][oldY].first;
			current.second = parents[oldX][oldY].second;
			rend.rectangle(Point2D(tempX+10, tempY+10), Point2D(current.first*20+10, current.second*20+10), al_map_rgb(255, 255, 0), false);
		}
		int tempX = current.first * 20;
		int tempY = current.second * 20;
		rend.rectangle(Point2D(tempX, tempY), Point2D(tempX + 20, tempY + 20), al_map_rgb(255, 255, 0), false);
		return current;
	}
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

	if (next.first > curBlock.first) {
		Keyboard::artificialSetDown(playerConfiguration->getMoveRIGHT());
	} else if (next.first < curBlock.first) {
		Keyboard::artificialSetDown(playerConfiguration->getMoveLEFT());
	} else if (next.second > curBlock.second) {
		Keyboard::artificialSetDown(playerConfiguration->getMoveDOWN());
	} else if  (next.second < curBlock.second) {
		Keyboard::artificialSetDown(playerConfiguration->getMoveUP());
	}
}
