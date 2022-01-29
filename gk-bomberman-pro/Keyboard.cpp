#include "Keyboard.h"

bool Keyboard::keys[ALLEGRO_KEY_MAX];
bool Keyboard::artificalKeyboard[ALLEGRO_KEY_MAX];

void Keyboard::setDown(int keyCode, bool down)
{
    if (keyCode < ALLEGRO_KEY_MAX) {
        keys[keyCode] = down;
    }
}

void Keyboard::artificialSetDown(int keyCode) {
    artificalKeyboard[keyCode] = true;
}

bool Keyboard::isKeyDown(int keyCode)
{
    if (keyCode < ALLEGRO_KEY_MAX) {
        if (artificalKeyboard[keyCode]) {
            artificalKeyboard[keyCode] = false;
            return true;
        }
        return Keyboard::keys[keyCode];
    }
    else {
        return false;
    }

}

