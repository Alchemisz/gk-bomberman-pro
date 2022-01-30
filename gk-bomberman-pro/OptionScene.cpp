#include "OptionScene.h"

void OptionScene::render()
{
	al_clear_to_color(al_map_rgb(0,0,0));
	al_draw_bitmap(help_screen, 0, 0, 0);
	button->draw();
	button->update();
}

void mainMenuScene() {
	SceneManager::setScene(new MainMenuScene());
}

void OptionScene::show()
{
	int centerX = ((1280 / 2)) - Button::BUTTON_WIDTH / 2;
	int posY = 500;
	button = new Button(centerX, posY);
	button->setText("Back To Menu");
	button->registerEventListener(mainMenuScene);
	help_screen = al_load_bitmap("gfx/helpscreen.png");
}

void OptionScene::dispose()
{
}
