#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <vector>
#include <iostream>
#include <random>

class AudioManager
{
private:
	bool active = true; //jak was leb boli od muzyki to mozna wylaczyc
	ALLEGRO_SAMPLE* MUSIC;
	ALLEGRO_SAMPLE* MENU_MUSIC;
	ALLEGRO_SAMPLE* BOOM;
	std::vector<ALLEGRO_SAMPLE*> EXPLOSION;
	unsigned int randCount = 0;

	static AudioManager* audioManger;
	AudioManager();

	ALLEGRO_SAMPLE_ID SAMPLE_POINTER;
public:
	static AudioManager* getInstance();
	void Play(std::string sample_name);
	void stopAllSamples();
};

