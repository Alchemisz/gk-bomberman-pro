#include "MapGenerator.h"
#include <random>
#include <time.h>

void MapGenerator::generateMap(Block blocks[12][12])
{
	srand(time(0));
	int randNumb;

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			blocks[i][j].setX(i * Block::WIDTH);
			blocks[i][j].setY(j * Block::WIDTH);
		}
	}
	for (int g = 0; g < 2; g++)
	{
		for (int k = 0; k < 2; k++)
		{
			randNumb = rand() % 5;

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					blocks[g * 3+i][k * 3+j].setBlockType(block_template[randNumb][i][j]);
				}
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			blocks[i][j].setBlockType(block_template[0][i][j]);
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			blocks[i][12 - j - 1].setBlockType(blocks[i][j].getBlockType());

		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			blocks[12 - i - 1][j].setBlockType(blocks[i][j].getBlockType());

		}
	}
}

void MapGenerator::generateTestMap(Block blocks[12][12])
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			blocks[i][j].setX(i * Block::WIDTH);
			blocks[i][j].setY(j * Block::WIDTH);
			blocks[i][j].setBlockType(AIR);
		}
	}

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (i == 0 || i == 11 || j == 0 || j == 11)blocks[i][j].setBlockType(STONE);
			if (i == 1 || i == 10 || j == 1 || j == 10)blocks[i][j].setBlockType(WALL);
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			blocks[i][j].setBlockType(AIR);
			blocks[11-i][11-j].setBlockType(AIR);
			blocks[11 - i][j].setBlockType(AIR);
			blocks[i][11 - j].setBlockType(AIR);

		}
	}

}

