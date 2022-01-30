#include "PrimitiveAnimation.h"

PrimitiveAnimation::PrimitiveAnimation(const char* filepath, int frames,int rows, int stepdelay, int height, int width)
{
	this->Animation = al_create_bitmap(height, width);
	this->Animation = al_load_bitmap(filepath);
	this->frames = frames;
	this->stepdelay = stepdelay;
	this->height = height;
	this->width = width;
	this->frametime = 0;
	this->rows = rows;
	al_convert_mask_to_alpha(this->Animation, al_map_rgb(255, 255, 0));
}

void PrimitiveAnimation::drawAnimation(int x, int y,int row)
{	
	//tak wiem dobry kod XD
	// rzad liczymy od 0, liczba rzadow w konstruktorze od 1
	al_draw_bitmap_region(this->Animation, (frametime / stepdelay) * (width / frames), row * (height / (rows)), (width / frames), height/rows, x, y, 0);
		this->frametime++;
		if (this->frametime == this->frames * this->stepdelay - 1)
			this->frametime = 0;
}

void PrimitiveAnimation::drawDefaultPosition(int x, int y,int row)
{
	al_draw_bitmap_region(this->Animation,0, row * (height / (rows)), (width / frames), (height / (rows)), x, y, 0);
	this->frametime = 0;
}

void PrimitiveAnimation::destroyAnimation()
{
	al_destroy_bitmap(Animation);
}
