#include "MainMenuScene.h"
#include "GameScene.h"
void MainMenuScene::render() {
	ALLEGRO_EVENT ev;
    ev.type = NULL;
	
    do {
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			SceneManager::setScene(new GameScene());
		}
    } while (al_get_next_event(this->eventQueue, &ev) != NULL);
	al_draw_line(0, 0, 1280, 720, al_map_rgb(0, 0, 0), 10);
}

void MainMenuScene::show()
{
	this->eventQueue = al_create_event_queue();
	al_register_event_source(this->eventQueue, al_get_mouse_event_source());
	al_register_event_source(this->eventQueue, al_get_keyboard_event_source());
	al_register_event_source(this->eventQueue, al_get_display_event_source(al_get_current_display()));
}

void MainMenuScene::dispose()
{
	al_destroy_event_queue(this->eventQueue);
}
