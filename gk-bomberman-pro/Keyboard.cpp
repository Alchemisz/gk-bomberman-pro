#include "Keyboard.h"

bool Keyboard::keys[ALLEGRO_KEY_MAX];

void Keyboard::setDown(int keyCode, bool down)
{  
    if (keyCode < ALLEGRO_KEY_MAX) {
        keys[keyCode] = down;
    }
}

bool Keyboard::isKeyDown(int keyCode)
{
    if (keyCode < ALLEGRO_KEY_MAX) {
        return Keyboard::keys[keyCode];
    } else {
        return false;
    }
    
}
