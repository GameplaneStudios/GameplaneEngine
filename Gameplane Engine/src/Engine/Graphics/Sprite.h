#pragma once

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class Sprite
{
public:
	Sprite(const char* filepath, SDL_Renderer* renderer);

	void draw(int x, int y)
	{
		destRect.x = x;
		destRect.y = y;
		destRect.w = width * xscale;
		destRect.h = height * yscale;

		SDL_RenderCopy(renderer, texture, NULL, &destRect);
	}

	int getWidth() { return width; }
	int getHeight() { return height; }
	
	int xscale = 1;
	int yscale = 1;

private:
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	SDL_Rect destRect;
	int width = 0;
	int height = 0;

};