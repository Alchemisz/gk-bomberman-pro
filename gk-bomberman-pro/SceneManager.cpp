#include "SceneManager.h"
Scene* SceneManager::scene = nullptr;
Engine* SceneManager::engine = nullptr;

void SceneManager::setScene(Scene* scene)
{
	if (SceneManager::engine != nullptr) {
		if (SceneManager::scene != nullptr) {
			SceneManager::engine->setScene(scene); 
			SceneManager::scene->dispose();
			delete SceneManager::scene;
			SceneManager::scene = scene;
		} else {
			SceneManager::engine->setScene(scene);
			SceneManager::scene = scene;
		}
		SceneManager::scene->show();
	}
}

void SceneManager::initialize(Engine* engine)
{
	SceneManager::engine = engine;
}
