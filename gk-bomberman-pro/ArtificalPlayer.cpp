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
				markedMap[curBlock.first][curBlock.second] |= AIR_MASK;
				break;
			case WALL:
				markedMap[curBlock.first][curBlock.second] |= WALL_MASK;
				break;
			case STONE:
				markedMap[curBlock.first][curBlock.second] |= STONE_MASK;
				break;
			}
		}
	}

	for (Bomb* bomb : bombList) {
		std::pair<int, int> bombPos = std::pair<int, int>((int)(bomb->getX() + 7) / Block::WIDTH, (int)(bomb->getY() + 7) / Block::WIDTH);
		markedMap[bombPos.first][bombPos.second] |= BOMB_MASK;
		for (direction dir : {LEFT, UP, RIGHT, DOWN}) {
			for (int i = 1; i < bomb->getPower(); i++) {
				switch (dir) {
				case LEFT:
					if (!(bombPos.first - i < 0)) {
						markedMap[bombPos.first - i][bombPos.second] |= DANGER_MASK;
					}
					break;
				case UP:
					if (!(bombPos.second - i < 0)) {
						markedMap[bombPos.first][bombPos.second - i] |= DANGER_MASK;
					}
					break;
				case RIGHT:
					if (!(bombPos.first + i < 0)) {
						markedMap[bombPos.first + i][bombPos.second] |= DANGER_MASK;
					}
					break;
				case DOWN:
					if (!(bombPos.second + i < 0)) {
						markedMap[bombPos.first][bombPos.second + i] |= DANGER_MASK;
					}
					break;
				}
			}
		}
	}
	for (Explosion* bomb : explosionList) {
		std::pair<int, int> bombPos = std::pair<int, int>((int)(bomb->getX() + 7) / Block::WIDTH, (int)(bomb->getY() + 7) / Block::WIDTH);
		markedMap[curBlock.first][curBlock.second] |= DANGER_MASK;
	}

}

void ArtificalPlayer::logic(Block blocks[12 + 1][12 + 1], std::list<Bomb*> bombList, std::list<Explosion*> explosionList)
{
	std::pair<int, int> curBlock = getBlockIndex();
	markMap(blocks, bombList, explosionList);
	if (markedMap[curBlock.first][curBlock.second] & DANGER_MASK) {
		Keyboard::artificialSetDown(playerConfiguration->getMoveLEFT());
	}
}
