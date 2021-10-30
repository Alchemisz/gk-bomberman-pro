#pragma once
#include <list>
#include "Scene.h"
#include "Engine.h"

class SceneManager
{
	private:
		static Engine* engine;
		static Scene* scene;
	public: 
		static void setScene(Scene* scene);
		static void initialize(Engine* engine);
};