#pragma once
#include "Scene.h"
#include "Button.h"
#include "SceneManager.h"
#include "MainMenuScene.h"

class OptionScene : public Scene
{
private:
	Button* button;
	ALLEGRO_BITMAP* help_screen;

public:
	virtual void render();
	virtual void show();
	virtual void dispose();
};

