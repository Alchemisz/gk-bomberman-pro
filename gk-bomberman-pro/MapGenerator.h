#pragma once
#include "Block.h"

#define BLOCKS_WIDTH_GEN 12
#define BLOCKS_HEIGHT_GEN 12

class MapGenerator
{	
private:
	BLOCK_TYPE block_template[7][3][3] = 
	{
	{	{AIR, AIR, WALL}, 
		{AIR, WALL, WALL}, 
		{WALL,WALL,STONE}
	},

	{	{WALL, AIR, WALL},
		{WALL, STONE, WALL},
		{WALL,AIR,WALL}
	},

	{	{STONE, WALL, STONE},
		{AIR, WALL, WALL},
		{STONE,WALL,STONE}
	},

	{	{AIR, STONE, AIR},
		{WALL, WALL, WALL},
		{AIR,STONE,AIR}
	},

	{	{AIR, AIR, AIR},
		{WALL, AIR, AIR},
		{WALL,WALL,WALL}
	},
	{	{WALL, WALL, WALL},
		{WALL, AIR, WALL},
		{WALL,WALL,WALL}
	},
	{	{WALL, WALL, WALL},
		{WALL, STONE, WALL},
		{WALL,WALL,WALL}
	},
	};
public:
	void generateMap(Block blocks[BLOCKS_WIDTH_GEN + 1][BLOCKS_HEIGHT_GEN + 1]);
	void generateTestMap(Block blocks[BLOCKS_WIDTH_GEN + 1][BLOCKS_HEIGHT_GEN + 1]);
};

