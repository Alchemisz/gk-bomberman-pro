#include "MainMenuScene.h"
void MainMenuScene::render() {

	al_clear_to_color(al_map_rgb(144, 238, 144));

	drawButtons();

	if (Keyboard::isKeyDown(ALLEGRO_KEY_W)) {
		SceneManager::setScene(new GameScene());
	}
}

void MainMenuScene::show()
{
	int centerX = (1280 / 2) - Button::BUTTON_WIDTH / 2;
	int posY = 200;

	for (int i = 0; i < 4; i++)
	{
		buttons[i] = new Button(centerX, posY);
		posY += 100;
	}

	buttons[SINGLEPLAYER]->setText("Singleplayer");
	buttons[MULTIPLAYER]->setText("Multiplayer");
	buttons[HELP]->setText("Help");
	buttons[EXIT]->setText("Exit");
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