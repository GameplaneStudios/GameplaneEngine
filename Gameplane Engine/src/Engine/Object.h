#pragma once

#include <SDL/SDL.h>
#include "Graphics/Sprite.h"

class Object
{
public:
	Object(int x, int y);

	Sprite* sprite = NULL;

	int x;
	int y;

	void update();
	void draw();

private:
	
};
