#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

class ScoreBox
{
private:
	bool active = false;
	int framesLeft = 0;
	const int framesActive = 120;
public:
	void setActive();
	void update(ALLEGRO_BITMAP* GFX_PLR1, ALLEGRO_BITMAP* GFX_PLR2, int score1, int score2);
};

