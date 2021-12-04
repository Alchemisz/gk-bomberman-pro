#include "AssetManager.h"

std::map<std::string, ALLEGRO_BITMAP*> AssetManager::bitmapAssets;
std::map<std::string, PrimitiveAnimation*> AssetManager::animationAssets;
BitmapHandler AssetManager::bitmapHandler;

void AssetManager::loadBitmap(std::string key, std::string path)
{
	ALLEGRO_BITMAP* bitmap = bitmapHandler.load_bitmap_from_file(path.c_str());
	bitmapAssets.insert(std::pair<std::string, ALLEGRO_BITMAP*>(key, bitmap));
}

void AssetManager::loadAnimation(std::string key, std::string path, int frames, int rows, int stepDelay, int x, int y)
{
	PrimitiveAnimation* primitiveAnimation = new PrimitiveAnimation(path.c_str(), frames, rows, stepDelay, x, y);
	animationAssets.insert(std::pair<std::string, PrimitiveAnimation*>(key, primitiveAnimation));
}


