#include "MainMenuScene.h"
void MainMenuScene::render() {

	al_clear_to_color(al_map_rgb(144, 238, 144));

	al_set_target_bitmap(background);
	background_animation->drawAnimation(0,0,0);
	al_set_target_bitmap(al_get_backbuffer(al_get_current_display()));
	al_draw_scaled_bitmap(background, 0, 0, 426, 240, 0, 0, 1280, 720, 0);

	updateButtons();
	drawButtons();
	al_draw_bitmap(ricardo_bomberman, 1280 - al_get_bitmap_width(ricardo_bomberman), 720 - al_get_bitmap_height(ricardo_bomberman), 0);
	//al_draw_bitmap(logo, 1280 - 960, 0, 0);
	al_draw_bitmap(logo, 20, 720 - 150 - 20, 0);
	
}

void singlePlayer() {
	SceneManager::setScene(new GameScene());
}

void multiPlayer() {
	SceneManager::setScene(new GameScene());
}

void options() {
	SceneManager::setScene(new OptionScene());
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
	buttons[SINGLEPLAYER]->registerEventListener(singlePlayer);
	buttons[MULTIPLAYER]->setText("Multiplayer");
	buttons[MULTIPLAYER]->registerEventListener(multiPlayer);
	buttons[HELP]->setText("Help");
	buttons[HELP]->registerEventListener(options);
	buttons[EXIT]->setText("Exit");

	Audio = new AudioManager();
	Audio->Play("menu");

	background = al_create_bitmap(426, 240);
	face = al_load_bitmap("gfx/face.png");
	logo = al_load_bitmap("gfx/logo.png");
	ricardo_bomberman = al_load_bitmap("gfx/ricbomb.png");
	al_convert_mask_to_alpha(face, al_map_rgb(255,255,0));
	al_convert_mask_to_alpha(logo, al_map_rgb(255, 255, 0));
	al_convert_mask_to_alpha(ricardo_bomberman, al_map_rgb(255, 255, 0));

	background_animation = new PrimitiveAnimation("gfx/animbg.png", 47, 1, 3, 240, 20022);
}

void MainMenuScene::dispose()
{
	Audio->stopSample();
}

void MainMenuScene::updateButtons()
{
	for (Button* button : buttons) {
		button->update();
	}
}

void MainMenuScene::drawButtons()
{
	for (Button* button : buttons) {
		button->draw();
	}
}