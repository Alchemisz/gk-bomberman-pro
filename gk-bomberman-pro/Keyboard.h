#pragma once
#include <allegro5/allegro.h>
class Keyboard {
public:
	static bool keys[ALLEGRO_KEY_MAX];
	static bool artificalKeyboard[ALLEGRO_KEY_MAX];
	static void setDown(int keyCode, bool down);
	static void artificialSetDown(int keyCode);
	static bool isKeyDown(int keyCode);
};