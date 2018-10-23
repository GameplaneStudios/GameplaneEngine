#include"Sprite.h"

Sprite::Sprite(const char* filepath, SDL_Renderer* renderer)
{
	texture = IMG_LoadTexture(renderer, filepath);
	this->renderer = renderer;

	SDL_QueryTexture(texture, NULL, NULL, &width, &height);
}