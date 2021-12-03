#include "ScoreBox.h"
#include "Engine.h"

void ScoreBox::setActive()
{
	framesLeft = framesActive;
	active = true;
}

void ScoreBox::update(ALLEGRO_BITMAP* GFX_PLR1, ALLEGRO_BITMAP* GFX_PLR2, int score1, int score2)
{
	if (!active)return;
	int box_x = (1280 - 460) / 2;
	int box_y = (720 - 160) / 2;
	al_draw_filled_rectangle(0, 0, 1280, 720, al_map_rgba(0, 0, 0, 200));
	al_draw_filled_rectangle(box_x, box_y, box_x + 460, box_y + 180, al_map_rgb(50, 50, 50));
	al_draw_rectangle(box_x+5, box_y+5, box_x + 460 - 5, box_y + 180 - 5, al_map_rgb(30, 30, 30),3);
	al_draw_bitmap(GFX_PLR1, box_x + 60, box_y + 50,0);
	al_draw_bitmap(GFX_PLR2, box_x + 480 - 60 - 70, box_y + 50,0);
	al_draw_textf(Engine::getInstance()->getFont(), al_map_rgb(255, 255, 255), box_x + 460 / 2, box_y + 180 / 2 - 60, ALLEGRO_ALIGN_CENTER, "Player 1 vs Player 2");
	al_draw_textf(Engine::getInstance()->getFont(), al_map_rgb(255, 255, 255), box_x + 460/2, box_y + 180/2, ALLEGRO_ALIGN_CENTER, "%d - %d",score1,score2);

	framesLeft = (framesLeft != 0) ? (framesLeft=framesLeft-1) : (active = false);
}
