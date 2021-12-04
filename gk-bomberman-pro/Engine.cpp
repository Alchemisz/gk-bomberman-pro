#include "Engine.h"

Engine *Engine::engine = nullptr;

Engine::Engine(EngineConfiguration config)
{
    this->config = config;
    this->font = nullptr;
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
    al_install_audio();
    al_init_acodec_addon();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();

    this->font = al_load_font("fonts/JosefinSans-Bold.ttf", 24, 0);

    display = al_create_display(config.getWidth(), config.getHeight());
    loopQueue = al_create_event_queue();
    float fps = 1.0 / (float)config.getFPS();
    loopTimer = al_create_timer(1.0 / (float)config.getFPS());
    al_register_event_source(loopQueue, al_get_timer_event_source(loopTimer));
    al_start_timer(loopTimer);
    SceneManager::setScene(new MainMenuScene());

    this->eventQueue = al_create_event_queue();
    al_register_event_source(this->eventQueue, al_get_mouse_event_source());
    al_register_event_source(this->eventQueue, al_get_keyboard_event_source());
    al_register_event_source(this->eventQueue, al_get_display_event_source(al_get_current_display()));
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

        ALLEGRO_EVENT ev;
        ALLEGRO_MOUSE_STATE mouseState;
        ev.type = NULL;

        do {
            if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                Keyboard::setDown(ev.keyboard.keycode, true);
            } else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
                Keyboard::setDown(ev.keyboard.keycode, false);
            }
            if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                running = false;
            }
        } while (al_get_next_event(this->eventQueue, &ev) != NULL);

        al_get_mouse_state(&mouseState);
        Mouse::x = mouseState.x;
        Mouse::y = mouseState.y;
        Mouse::mouseDown = al_mouse_button_down(&mouseState, 1);

        SceneManager::update();
        SceneManager::scene->render();

        al_flip_display();
        ev.type = NULL;
    }
    this->close();
}

void Engine::close()
{
    al_destroy_event_queue(this->loopQueue);
    al_destroy_event_queue(this->eventQueue);
    al_destroy_display(this->display);
}

ALLEGRO_FONT* Engine::getFont()
{
    return this->font;
}

Engine* Engine::getInstance()
{
    if (engine == nullptr) {
        engine = new Engine(EngineConfiguration::getDefault());
    }
    return engine;
}
