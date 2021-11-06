#pragma once
#include "Block.h"

class MapGenerator
{	
private:
	BLOCK_TYPE block_template[5][3][3] = 
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
	};
public:
	void generateMap(Block blocks[12][12]);
	void generateTestMap(Block blocks[12][12]);
};

