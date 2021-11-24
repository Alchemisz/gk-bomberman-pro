#include <allegro5/allegro.h>
class BitmapHandler
{
public:
	ALLEGRO_BITMAP* create_bitmap(int w, int h);
	ALLEGRO_BITMAP* load_bitmap_from_file(const char*path);
	bool save_bitmap_to_file(const char* path,ALLEGRO_BITMAP* BITMAP);
	void delete_bitmap(ALLEGRO_BITMAP* BITMAP);
};
