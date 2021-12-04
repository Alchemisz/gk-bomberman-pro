#pragma once
#include <allegro5/allegro.h>
#include <iostream>
#include "Bitmaphandler.h"
#include "PrimitiveAnimation.h"
#include <map>
class AssetManager
{
public:
	static std::map<std::string, ALLEGRO_BITMAP*> bitmapAssets;
	static std::map<std::string, PrimitiveAnimation*> animationAssets;
	static BitmapHandler bitmapHandler;

	static void loadBitmap(std::string key, std::string path);
	static void loadAnimation(std::string key, std::string path, int frames, int rows, int stepDelay, int x, int y);
	static void freeBitmap(std::string key);
	static void freeAnimation(std::string key);
};

