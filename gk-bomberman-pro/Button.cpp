#include "Button.h"
#include "Engine.h"
void Button::draw()
{
	al_draw_filled_rectangle(this->x, this->y, this->x + Button::BUTTON_WIDTH,  this->y + Button::BUTTON_HEIGHT, this->frameColor);
	al_draw_filled_rectangle(this->x + FRAME_MARGIN,
							this->y + FRAME_MARGIN,
							this->x + Button::BUTTON_WIDTH - FRAME_MARGIN,
							this->y + Button::BUTTON_HEIGHT - FRAME_MARGIN,
							this->buttonColor);


}

Button::Button(int x, int y) {
	this->x = x;
	this->y = y;
	this->buttonColor = Color::Gray;
	this->frameColor = Color::Black;
}

void Button::setText(std::string text)
{
	this->text = text;
}

std::string Button::getText() {
	return this->text;
}
