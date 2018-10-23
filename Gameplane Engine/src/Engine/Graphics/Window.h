#pragma once

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>

class Window
{
public:
	Window();
	~Window();

	void init(const char* title, int width, int height, bool fullscreen = false);
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen = false);

	void handleEvents();
	void update();
	void beginRender();
	void endRender();
	void clean();

	bool running() { return isRunning; }

	char* getTitle() { return title; }

	int getWidth() { return width; }

	int getHeight() { return height; }

	SDL_Renderer* getRenderer() { return renderer; }

private:
	int cnt = 0;
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;

	char* title;
	int width = -1;
	int height = -1;

};
