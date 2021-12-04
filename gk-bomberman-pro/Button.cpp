#include "Button.h"
#include "Engine.h"

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
void Button::draw()
{
	ALLEGRO_FONT* font = Engine::getInstance()->getFont();


	if (hover) {
		al_draw_filled_rectangle(this->x, this->y, this->x + Button::BUTTON_WIDTH, this->y + Button::BUTTON_HEIGHT, this->frameColor);
		al_draw_filled_rectangle(this->x + FRAME_MARGIN,
			this->y + FRAME_MARGIN,
			this->x + Button::BUTTON_WIDTH - FRAME_MARGIN,
			this->y + Button::BUTTON_HEIGHT - FRAME_MARGIN,
			Color::White);
	}
	else {
		al_draw_filled_rectangle(this->x, this->y, this->x + Button::BUTTON_WIDTH, this->y + Button::BUTTON_HEIGHT, this->frameColor);
		al_draw_filled_rectangle(this->x + FRAME_MARGIN,
			this->y + FRAME_MARGIN,
			this->x + Button::BUTTON_WIDTH - FRAME_MARGIN,
			this->y + Button::BUTTON_HEIGHT - FRAME_MARGIN,
			this->buttonColor);
	}

	al_draw_text(font, Color::Black, this->x + (Button::BUTTON_WIDTH / 2),
		(this->y + Button::BUTTON_HEIGHT / 3), ALLEGRO_ALIGN_CENTRE, this->text.c_str());

}

void Button::update() {
	if (Mouse::x > this->x && Mouse::x < this->x + this->BUTTON_WIDTH && Mouse::y > this->y && Mouse::y < this->y + this->BUTTON_HEIGHT) {
		this->hover = true;
		if (Mouse::mouseDown) {
			this->handler();
		}
	}
	else {
		this->hover = false;
	}
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

void Button::registerEventListener(void(*handler)(void))
{
	this->handler = handler;
}

std::string Button::getText() {
	return this->text;
}
