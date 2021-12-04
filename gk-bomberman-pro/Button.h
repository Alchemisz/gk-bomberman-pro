#pragma once
#include <allegro5/allegro_primitives.h>
#include "Color.h"
#include <iostream>
#include "Mouse.h"

class Button
{
private:
	int x, y;
	std::string text;
	ALLEGRO_COLOR buttonColor;
	ALLEGRO_COLOR frameColor;
	const int FRAME_MARGIN = 10;
public:
	static const int BUTTON_WIDTH = 240;
	static const int BUTTON_HEIGHT = 60;
	bool hover = false;
	void (*handler)(void) = 0;
	void draw();
	void update();
	Button(int x, int y);
	void registerEventListener(void (*handler)(void));
	void setText(std::string text);
	std::string getText();
};

