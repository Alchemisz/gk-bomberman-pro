#include "EngineConfiguration.h"

EngineConfiguration EngineConfiguration::getDefault()
{
	EngineConfiguration config;
	config.setFPS(60);
	config.setWidth(1280);
	config.setHeight(720);
	return config;
}

void EngineConfiguration::setHeight(int value)
{
	this->height = value;
}

void EngineConfiguration::setWidth(int value)
{
	this->width = value;
}

void EngineConfiguration::setFPS(int value)
{
	this->FPS = value;
}

int EngineConfiguration::getHeight()
{
	return this->height;
}

int EngineConfiguration::getWidth()
{
	return this->width;
}

int EngineConfiguration::getFPS()
{
	return this->FPS;
}