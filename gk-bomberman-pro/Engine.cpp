#include "Engine.h"

Engine::Engine(EngineConfiguration config)
{
    this->config = config;
}

void Engine::clearScreen(ALLEGRO_COLOR color)
{
    al_clear_to_color(color);
}

void Engine::errorMessage(std::string title, std::string heading, std::string errorMsg)
{
    al_show_native_message_box(this->display, title.c_str(), heading.c_str(), errorMsg.c_str(), NULL, ALLEGRO_MESSAGEBOX_ERROR);
}

void Engine::init()
{
    al_init();
    al_install_mouse();
    al_install_keyboard();
    al_init_primitives_addon();
    display = al_create_display(config.getWidth(), config.getHeight());
    eventQueue = al_create_event_queue();
    loopQueue = al_create_event_queue();
    loopTimer = al_create_timer(1.0 / config.getFPS());
    al_register_event_source(loopQueue, al_get_timer_event_source(loopTimer));
    al_start_timer(loopTimer);

    al_register_event_source(eventQueue, al_get_mouse_event_source());
    al_register_event_source(eventQueue, al_get_keyboard_event_source());
    al_register_event_source(eventQueue, al_get_display_event_source(display));
}

void Engine::loop()
{
    ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);
    ALLEGRO_EVENT ev;
    bool running = true;
    while (running)
    {
        al_wait_for_event(loopQueue, &ev);
        clearScreen(white);
        ev.type = NULL;
        do {
            if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                running = false;
            }
            clearScreen(al_map_rgb(255, 0, 0));
            al_draw_line(0, 0, 1280, 720, al_map_rgb(0, 0, 0), 10);

        } while (al_get_next_event(eventQueue, &ev) != NULL);
        al_flip_display();
        ev.type = NULL;
    }
    errorMessage("test", "test", "test");
    this->close();
}

void Engine::close()
{
    al_destroy_event_queue(this->loopQueue);
    al_destroy_event_queue(this->eventQueue);
    al_destroy_display(this->display);
}