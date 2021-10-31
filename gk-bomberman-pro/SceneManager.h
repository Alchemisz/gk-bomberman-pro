#pragma once
#include <list>
#include "Scene.h"

class SceneManager
{
	private:
		static Scene* newScene;
	public: 
		static Scene* scene;
		static void setScene(Scene* scene);
		static void update();
};