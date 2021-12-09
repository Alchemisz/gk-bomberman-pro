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

	ALLEGRO_SAMPLE_ID SAMPLE_POINTER;
public:
	AudioManager();
	void Play(std::string sample_name);
	void stopSample();
};

