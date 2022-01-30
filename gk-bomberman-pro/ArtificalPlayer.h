#pragma once
#include "Player.h"
#include "Keyboard.h"
#include "Block.h"
#include "Bomb.h"
#include "Explosion.h"
#include <stack>
#include <list>
#include <queue>

const int WALL_MASK = 1;
const int DANGER_MASK = WALL_MASK << 1;
const int BIG_DANGER_MASK = DANGER_MASK << 1;
const int ENEMY_MASK = BIG_DANGER_MASK << 1;
const int AIR_MASK = ENEMY_MASK << 1;
const int BOMB_MASK = AIR_MASK << 1;
const int STONE_MASK = BOMB_MASK << 1;
const int ME_MASK = STONE_MASK << 1;
const int ACCESIBLE_MASK = ME_MASK << 1;

/*!
 * @brief Klasa reprezentujaca gracza sterowanego sztuczna inteligencja
*/
class ArtificalPlayer : public Player
{
private:
	//! Czy gracz jest sterowany komputerem
	const bool isArtifical = true;
	//! Cel poruszania gracza
	std::pair<int, int> nextBlock = { 0, 0 };
	//! Czy gracz znajduje sie w niebezpieczenstwie
	bool danger = false;
	//! Licznik bomb
	int bombCounter = 0;
	//! Czy gracz jest agresywny
	int aggressive = true;
	//! Mapa do wyznaczania trasy
	int markedMap[12 + 1][12 + 1];
public:
	/*!
	 * @brief Zwraca czy gracz jest sterowany komputerem
	 * @return Czy gracz jest sterowany komputerem
	*/
	virtual bool getIsArtifical();
	/*!
	 * @brief Porusza graczem w lewo
	*/
	void moveLeft();
	/*!
	 * @brief Znajduje najblizszy bezpieczny bloczek
	 * @param blocks Bloczki z gry
	 * @return Indeks bezpiecznego bloczku
	*/
	std::pair<int, int> closestSafe(Block blocks[12 + 1][12 + 1]);
	/*!
	 * @brief Tworzy oznaczona mape gry
	 * @param blocks Bloczki z gry
	 * @param bombList Lista bomb
	 * @param explosionList Lista eksplozji
	*/
	void markMap(Block blocks[12 + 1][12 + 1], std::list<Bomb*> bombList, std::list<Explosion*> explosionList);
	/*!
	 * @brief Tworzy trase do celu
	 * @param destX Wspolrzedna x celu
	 * @param destY Wspolrzedna y celu
	 * @return Vector zawierajacy trase
	*/
	std::vector<std::pair<int, int>> findPath(int destX, int destY);
	/*!
	 * @brief Tworzy najblizsza trase do celu
	 * @param destX Wspolrzedna x celu
	 * @param destY Wspolrzedna y celu
	 * @return Vector zawierajacy trase
	*/
	std::vector<std::pair<int, int>> findBlockedPath(int destX, int destY);
	/*!
	 * @brief Wykonuje logiczne cele AI
	 * @param blocks Bloczki z gry
	 * @param bombList Lista bomb
	 * @param explosionList Lista eksplozji
	 * @param player Gracz
	*/
	void logic(Block blocks[12 + 1][12 + 1], std::list<Bomb*>& bombList, std::list<Explosion*>& explosionList, Player& player);
};

