#include "MainMenuScene.h"
void MainMenuScene::render() {
			
	if (Keyboard::isKeyDown(ALLEGRO_KEY_W)) {
		SceneManager::setScene(new GameScene());
	}
	al_draw_line(0, 0, 1280, 720, al_map_rgb(0, 0, 0), 10);
}

void MainMenuScene::show()
{
}

void MainMenuScene::dispose()
{
}
