#pragma once
/*!
 * @brief Klasa reprezentujaca scene
*/
class Scene
{
	protected:
		//! Czy scena jest aktywna
		bool running = true;
	public:
		/*!
		 * @brief Renderuje scene
		*/
		virtual void render() = 0;
		/*!
		 * @brief Inicjalizuje scene
		*/
		virtual void show() = 0;
		/*!
		 * @brief Sprzata smieci po scenie
		*/
		virtual void dispose() = 0;
};

