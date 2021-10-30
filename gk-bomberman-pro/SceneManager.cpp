#include "SceneManager.h"

void SceneManager::setScene(Scene scene)
{
	
}

SceneManager::SceneManager()
{
	this->currentScene = nullptr;
}

void SceneManager::setScene(Scene* scene)
{
	if (currentScene != nullptr) {
		delete currentScene;
	}
	this->currentScene = scene;
}
