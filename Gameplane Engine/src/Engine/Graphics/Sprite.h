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
		destRect.w = width;
		destRect.h = height;

		SDL_RenderCopy(renderer, texture, NULL, &destRect);
	}

private:
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	SDL_Rect destRect;
	int width = 0;
	int height = 0;

};