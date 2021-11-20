
#include "BitmapHandler.h"

ALLEGRO_BITMAP* BitmapHandler::create_bitmap(int w, int h)
{
	return al_create_bitmap(w,h);
}

ALLEGRO_BITMAP* BitmapHandler::load_bitmap_from_file(const char* path)
{
	return al_load_bitmap(path);
}

bool BitmapHandler::save_bitmap_to_file(const char* path, ALLEGRO_BITMAP* BITMAP)
{
	return al_save_bitmap(path,BITMAP);
}
void BitmapHandler::delete_bitmap(ALLEGRO_BITMAP* BITMAP)
{
	al_destroy_bitmap(BITMAP);
}
