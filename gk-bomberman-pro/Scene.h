#pragma once
class Scene
{
	public:
		virtual void render() = 0;
		virtual void show() = 0;
		virtual void dispose() = 0;
};

