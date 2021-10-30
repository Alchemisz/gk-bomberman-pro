#pragma once
#include <list>
#include "Scene.h"

class SceneManager
{
	private:
		Scene* currentScene;
	public: 
		SceneManager();
		void setScene(Scene* scene);
};