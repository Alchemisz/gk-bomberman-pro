#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "SceneManager.h"
#include "DebugScene.h"
#include "Scene.h"
#include "Block.h"
#include <iostream>
#include "MapGenerator.h"
#include "PrimitiveAnimation.h"
#include "Keyboard.h"
#include "Player.h"
#include "Bomb.h"
#include "Explosion.h"
#include "Engine.h"
#include "ScoreBox.h"
#include "ArtificalPlayer.h"
#include "AudioManager.h"

//! Szerokosc bloczkow
const int BLOCKS_WIDTH = 12;
//! Wysokosc bloczkow
const int BLOCKS_HEIGHT = 12;

/*!
 * @brief Klasa reprezentujaca scene gry
*/
class GameScene : public Scene
{
private:
	//! Czasomierz do zycia bomby
	ALLEGRO_TIMER* bombTimer;
	//! Kolejka zdarzen do bomby
	ALLEGRO_EVENT_QUEUE* bombTimerQueue;
	//! Poziom skalowania
	static const int SCALLING_LEVEL = 3;
	//! Szerokosc mapy
	const int MAP_WIDTH = 240;
	//! Wysokosc mapy
	const int MAP_HEIGHT = 240;

	//! Bloczki gry
	Block blocks[BLOCKS_WIDTH + 1][BLOCKS_HEIGHT + 1];
	//! Grafika podlogi 
	ALLEGRO_BITMAP* block_floor;
	//! Grafika sciany
	ALLEGRO_BITMAP* block_wall;
	//! Grafika twardej sciany
	ALLEGRO_BITMAP* block_stone;
	//! Grafika granicy sciany
	ALLEGRO_BITMAP* block_wall_border[4];
	//! Lista graczy
	std::list<Player*> playerList;
	//! Grafika swiata
	ALLEGRO_BITMAP* main_world;
	//! Tlo gry
	ALLEGRO_BITMAP* game_background;
	//! Grafika tarczy gracza
	ALLEGRO_BITMAP* player_shield;
	//! Grafika bonusu niezniczalnosci
	ALLEGRO_BITMAP* bonus_inv;
	//! Grafika bonusu bomy
	ALLEGRO_BITMAP* bonus_bomb;
	//! Grafika bonusu poteznej bomby
	ALLEGRO_BITMAP* bonus_nuke;
	//! Grafika bonusu wiekszej szybkosci gracza
	ALLEGRO_BITMAP* bonus_speed;
	//! Grafika pustego bonusu
	ALLEGRO_BITMAP* bonus_null;

	//! Generator map
	MapGenerator MapGen;
	//! Animacja gracza 1
	PrimitiveAnimation *PlayerAnim;
	//! Animacja gracza 2
	PrimitiveAnimation *PlayerAnim2;
	//! Animacja bomby
	PrimitiveAnimation *BombAnim;
	//! Animacja eksplozji 1
	PrimitiveAnimation* explosionAnimation_up;
	//! Animacja eksplozji 2
	PrimitiveAnimation* explosionAnimation_down;
	//! Animacja eksplozji 3
	PrimitiveAnimation* explosionAnimation_left;
	//! Animacja eksplozji 4
	PrimitiveAnimation* explosionAnimation_right;
	//! Animacja eksplozji 5
	PrimitiveAnimation* explosionAnimation_center;

	//! Ikona gracza 1
	ALLEGRO_BITMAP* Player1Icon;
	//! Ikona gracza 2
	ALLEGRO_BITMAP* Player2Icon;
	//! Gracz
	Player player;

	//! Lista bomb
	std::list<Bomb*> bombList;
	//! Lista eksplozji
	std::list<Explosion*> explosionList;

	//! Czasomierz bonusow
	int BonusFrameTimer = 0;
	//! Granica czasomierza bonusow
	const int BonusFrameTimerBoundry = 300;

	//! Okno pokazujace wynik
	ScoreBox* SBox;
	//! Menadzer audio w grze
	AudioManager *Audio;
	/*!
	 * @brief Rysuje obecny bonus
	 * @param x Wspolrzedna x
	 * @param y Wspolrzedna y
	 * @param player Wskaznik na gracza posiadajacego bonus
	*/
	void DrawCurrentBonus(int x,int y,Player* player);
	/*!
	 * @brief Obsluguje zdarzenia zwiazane z bonusem
	*/
	void BonusHandler();
	/*!
	 * @brief Aktualizuje stan gracza
	 * @param player Gracz
	*/
	void playerUpdate(Player& player);
	/*!
	 * @brief Rysuje bomby na ekranie
	*/
	void bombRender();
	/*!
	 * @brief Rysuje eksplozje na ekranie
	*/
	void renderExplosions();
	/*!
	 * @brief Aktualizuje stan eksplozji
	*/
	void updateExplosions();
	/*!
	 * @brief Sprawdza kolizje graczy ze swiatem
	*/
	void checkCollisions();
	/*!
	 * @brief Resetuje stan gry
	*/
	void resetGame();
	//! Wartosc reprezentujaca tryb gry (Multiplayer, Singleplayer)
	bool multi = false;
public:
	/*!
	 * @brief Konstruktor domyslny z trybem gry
	 * @param multi Tryb gry
	*/
	GameScene(bool multi);
	/*!
	 * @brief Renderuje scene
	*/
	virtual void render();
	/*!
	 * @brief Inicjalizuje scene
	*/
	virtual void show();
	/*!
	 * @brief Sprzata pozostalosci po scenie
	*/
	virtual void dispose();
};
