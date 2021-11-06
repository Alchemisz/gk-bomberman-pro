#include "MainMenuScene.h"
void MainMenuScene::render() {

	al_clear_to_color(al_map_rgb(144, 238, 144));

	al_set_target_bitmap(background);
	background_animation->drawAnimation(0,0,0);
	al_set_target_bitmap(al_get_backbuffer(al_get_current_display()));
	al_draw_scaled_bitmap(background, 0, 0, 426, 240, 0, 0, 1280, 720, 0);

	drawButtons();

	if (Keyboard::isKeyDown(ALLEGRO_KEY_W)) {
		SceneManager::setScene(new GameScene());
	}
}

void MainMenuScene::show()
{
	//int centerX = (1280 / 2) - Button::BUTTON_WIDTH / 2;
	int centerX = ((1280 / 6) * 1) - Button::BUTTON_WIDTH / 2;
	int posY = 160;

	for (int i = 0; i < 4; i++)
	{
		buttons[i] = new Button(centerX, posY);
		posY += 100;
	}

	buttons[SINGLEPLAYER]->setText("Singleplayer");
	buttons[MULTIPLAYER]->setText("Multiplayer");
	buttons[HELP]->setText("Help");
	buttons[EXIT]->setText("Exit");

	background = al_create_bitmap(426, 240);
	background_animation = new PrimitiveAnimation("gfx/animbg.png", 47, 1, 3, 240, 20022);
}

void MainMenuScene::dispose()
{
}

void MainMenuScene::drawButtons()
{
	for (Button* button : buttons) {
		button->draw();
	}
}