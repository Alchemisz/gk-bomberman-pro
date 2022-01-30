#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
#include "Block.h"
#include "PlayerConfiguration.h"


enum direction {
	LEFT = 0,UP,RIGHT,DOWN,CENTER
};

enum bonus_types {
	NO_BONUS = 0, INVINCIBILITY, SPEED,BONUS_BOMBS, STRONGER_BOMBS
};

/*!
 * @brief Klasa do reprezentacji gracza
*/
class Player
{
private:
	//! Wspolrzedna x
	float x;
	//! Wspolrzedna y
	float y;
	//! Predkosc gracza
	float velocity = 1;
	//! Moc bomby
	int power = 3;
	//! Czy gracz sie porusza
	bool isMoving;
	//! Wynik
	int score = 0;
	//! Czy jest sterowany przez AI
	const bool isArtifical = false;
	//! Kierunek gracza
	direction state;
protected:
	//! Konfiguracja gracza
	PlayerConfiguration* playerConfiguration;
public:
	//! Obecny stan konta kredytow do stawiania bomb
	int bombCredits = 0;
	//! Limit stanu konta kredytow
	int maxBombCredits = 90;
	//! Koszt postawienia bomby
	const int bombCreditsCost = 90;
	//! Szerokosc bomby
	static const int PLAYER_WIDTH = 14;
	//! Niezniszczalonosc
	bool bonus_invincibility = false;
	bonus_types bonus_type = NO_BONUS;
	
	/*!
	 * @brief Ustawia nowa wartosc x
	 * @param x Nowa wartosc
	*/
	void setX(float x);
	/*!
	 * @brief Ustawia nowa wartosc y
	 * @param y Nowa wartosc
	*/
	void setY(float y);
	/*!
	* @brief Ustawia nowa predkosc
	* @param newWelocity Nowa wartosc
	*/
	void setVelocity(float newVelocity);
	/*!
	 * @brief Zwraca predkosc gracza
	 * @return Wartosc predkosci
	*/
	float getVelocity();
	/*!
	* @brief Zwraca wspolrzedna x gracza
	* @return Wartosc x
	*/
	float getX();
	/*!
	* @brief Zwraca wspolrzedna y gracza
	* @return Wartosc y
	*/
	float getY();
	/*!
	* @brief Zwraca czy gracz porusza sie
	* @return Czy gracz sie porusza
	*/
	bool getIsMoving();
	/*!
	* @brief Ustawia, czy gracz sie porusza
	* @param Nowa wartosc
	*/
	void setIsMoving(bool moving);
	/*!
	* @brief Zwraca moc bomb gracza
	* @return Wartosc mocy
	*/
	int getPower();
	/*!
	* @brief Ustawia moc bomb
	* @return Nowa wartosc
	*/
	void setPower(int power);
	/*!
	* @brief Zwraca kierunek gracza
	* @return Kierunek
	*/
	direction getPositionState();
	/*!
	* @brief Ustawia kierunek gracza
	* @param state Nowy kierunek
	*/
	void setPositionState(direction state);
	/*!
	* @brief Zwraca indeks bloczku w ktorym znajduje sie gracz
	* @return Indeks bloczku
	*/
	std::pair<int, int> getBlockIndex();
	/*!
	* @brief Zwraca konfiguracje gracza
	* @return Konfiguracja
	*/
	PlayerConfiguration* getPlayerConfiguration();
	/*!
	* @brief Ustawia konfiguracje gracza
	* @param playerConfiguration Nowa konfiguracja
	*/
	void setPlayerConfiguration(PlayerConfiguration* playerConfiguration);
	/*!
	* @brief Zwraca, czy gracz jest sterowany przez AI
	* @return Czy gracz jest kierowany AI
	*/	
	virtual bool getIsArtifical();
	/*!
	* @brief Tworzy nowy losowy bonus
	*/
	void generateRandomBonus();
	/*!
	* @brief Zwieksza wynik gracza
	*/
	void incScore();
	/*!
	* @brief Resetuje stan bonusu
	*/
	void resetBonus();
	/*!
	* @brief Zwraca wynik gracza
	* @return Wynik gracza
	*/
	int getScore();
	/*!
	* @brief Porusza graczem
	*/
	void move();
	/*!
	* @brief Rysuje gracza na ekranie
	*/
	void drawPlayer();
};

