#include "AudioManager.h"

AudioManager::AudioManager()
{
	SAMPLE_POINTER;
	al_reserve_samples(6);
	MUSIC = al_load_sample("sfx/music.mp3");
	MENU_MUSIC = al_load_sample("sfx/menu.mp3");
	BOOM = al_load_sample("sfx/boom.mp3");
	EXPLOSION.push_back(al_load_sample("sfx/exp1.mp3"));
	EXPLOSION.push_back(al_load_sample("sfx/exp2.mp3"));
	EXPLOSION.push_back(al_load_sample("sfx/exp3.mp3"));
	EXPLOSION.push_back(al_load_sample("sfx/exp4.mp3"));

	srand(69);

}

void AudioManager::Play(std::string sample_name)
{

	if (!active)return;
	if(sample_name == "menu")
		al_play_sample(MENU_MUSIC, 0.5, 0, 1, ALLEGRO_PLAYMODE_LOOP, &SAMPLE_POINTER);
	if (sample_name == "boom")
		al_play_sample(BOOM, 1.0, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
	if(sample_name == "music")
		al_play_sample(MUSIC, 0.5, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);
	if (sample_name == "explosion")
	{
		al_play_sample(EXPLOSION[(rand()+randCount) % (EXPLOSION.size() - 1)], 1.0, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
		randCount++;
	}

}

void AudioManager::stopSample()
{
	al_stop_sample(&SAMPLE_POINTER);
}
