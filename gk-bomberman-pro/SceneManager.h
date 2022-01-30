#pragma once
#include <list>
#include "Scene.h"
/*!
 * @brief Klasa do zarzadzania scenai
*/
class SceneManager
{
	private:
		//! Wskaznik na nowa scene
		static Scene* newScene;
	public: 
		//! Wskaznik na obecna scene
		static Scene* scene;
		/*!
		 * @brief Ustawia obecna scene
		 * @param scene Wskaznik na scene
		*/
		static void setScene(Scene* scene);
		/*!
		 * @brief Aktualizuje stan menadzera scen
		*/
		static void update();
};