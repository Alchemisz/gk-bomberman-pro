#include "DebugScene.h"
#include <iostream>


void DebugScene::render() {
	ALLEGRO_EVENT ev;
	ev.type = NULL;

	//i = (i + 10) % 700;
	//al_draw_line(0, 0, 1280, i, al_map_rgb(0, 0, 0), 10);

	Point2D p1 = Point2D(200, 200);
	
	renderer.circle_lab(p1, 50, al_map_rgb(255, 0, 0));
	//renderer.rectangle(Point2D(100, 100), Point2D(300,300), al_map_rgb(255, 0, 0), false);
	//renderer.elipse_lab(Point2D(400, 400), 50,100, al_map_rgb(255, 0, 255));
	renderer.boundry_fill(p1, al_map_rgb(255, 0, 255), al_map_rgb(255, 0, 0));

	p1.translate(100, 50);
	renderer.circle_lab(p1, 50, al_map_rgb(255, 0, 0));
	renderer.boundry_fill(p1, al_map_rgb(255, 0, 255), al_map_rgb(255, 0, 0));

	p1.scale(3);
	renderer.circle_lab(p1, 50, al_map_rgb(255, 0, 0));
	renderer.boundry_fill(p1, al_map_rgb(255, 0, 255), al_map_rgb(255, 0, 0));
}

void DebugScene::show()
{
	this->eventQueue = al_create_event_queue();
	al_register_event_source(this->eventQueue, al_get_mouse_event_source());
	al_register_event_source(this->eventQueue, al_get_keyboard_event_source());
	al_register_event_source(this->eventQueue, al_get_display_event_source(al_get_current_display()));


}

void DebugScene::dispose()
{
	al_destroy_event_queue(this->eventQueue);
}