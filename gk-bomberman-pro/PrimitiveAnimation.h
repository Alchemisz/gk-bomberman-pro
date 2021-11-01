#pragma once
#include <allegro5/allegro.h>

class PrimitiveAnimation
{
private:
	ALLEGRO_BITMAP* Animation;
	int frames, stepdelay,height,width,frametime,rows;
public:
	PrimitiveAnimation(const char* filepath, int frames,int rows, int stepdelay, int height, int width);
	void drawAnimation(int x,int y,int row);
	void drawDefaultPosition(int x, int y,int row);

};

