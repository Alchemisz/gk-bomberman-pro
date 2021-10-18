#pragma once
class EngineConfiguration
{
private:
	int width;
	int height;
	int FPS;
public:
	bool keyboard, mouse, isFullScreen;

	static EngineConfiguration getDefault();

	void setHeight(int value);
	void setWidth(int value);
	void setFPS(int value);
	int getHeight();
	int getWidth();
	int getFPS();
};
