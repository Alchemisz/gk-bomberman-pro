#pragma once
#include <allegro5/allegro.h>
class Keyboard {
	public:
		static bool keys[ALLEGRO_KEY_MAX];
		static void setDown(int keyCode, bool down);
		static bool isKeyDown(int keyCode);
};