#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#define RES_H 720
#define RES_W 1280
#define RED al_map_rgb(255,0,0)
#define BLACK al_map_rgb(0,0,0)

int main()
{
	al_init();
	al_init_primitives_addon();
	ALLEGRO_DISPLAY* DISPLAY = al_create_display(RES_W,RES_H);

	while (true)
	{
		al_clear_to_color(RED);
		al_draw_line(0, 0, RES_W, RES_H, BLACK, 10);
		al_flip_display();
	}


	al_destroy_display(DISPLAY);
}