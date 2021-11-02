#pragma once
#include <allegro5/allegro_primitives.h>
#include "Color.h"
#include "Button.h"
#include <iostream>
#include "Engine.h"

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
	void draw();
	Button(int x, int y);
	//void setText(std::string text);
	//std::string getText();
};

