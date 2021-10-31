#include "SceneManager.h"
Scene* SceneManager::scene = nullptr;
Scene* SceneManager::newScene = nullptr;

void SceneManager::setScene(Scene* scene)
{
	if (SceneManager::newScene == nullptr) {
		SceneManager::newScene = scene;
	}
	else {
		delete SceneManager::newScene;
		SceneManager::newScene = scene;
	}
}

void SceneManager::update()
{
	if (SceneManager::newScene == nullptr) {
		return;
	} else {
		if (SceneManager::scene != nullptr) {
			SceneManager::scene->dispose();
			delete SceneManager::scene;
		}
		SceneManager::scene = SceneManager::newScene;
		SceneManager::newScene = nullptr;
		SceneManager::scene->show();
	}
}

