#include "Engine.h"

void Engine::init()
{
	al_init();
	display = al_create_display(config.getWidth(), config.getHeight());
    eventQueue = al_create_event_queue();
    loopTimer = al_create_timer(1.0 / config.getFPS());
    al_register_event_source(eventQueue, al_get_timer_event_source(loopTimer));
    al_start_timer(loopTimer);

    al_register_event_source(eventQueue, al_get_mouse_event_source());
    al_register_event_source(eventQueue, al_get_keyboard_event_source());
    al_register_event_source(eventQueue, al_get_display_event_source(display));


}

void Engine::loop()
{
    while (true)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(eventQueue, &ev);

        if (ev.type == ALLEGRO_EVENT_TIMER) {
            redraw = true;
        }
        else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }

        if (redraw && al_event_queue_is_empty(eventQueue)) {
            redraw = false;
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_flip_display();
        }
    }

}
