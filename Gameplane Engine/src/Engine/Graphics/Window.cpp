#include "Window.h"

SDL_Texture* gpTex;

Window::Window() {}

Window::~Window() {}

void Window::init(const char* title, int width, int height, bool fullscreen)
{
	init(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, fullscreen);
}

void Window::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	isRunning = false;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystem initialized" << std::endl;

		int flags = 0;
		if (fullscreen) { flags = SDL_WINDOW_FULLSCREEN; }

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window created" << std::endl;

			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer)
			{
				std::cout << "Renderer created" << std::endl;
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				isRunning = true;

				this->title = (char*)title;
				this->width = width;
				this->height = height;

				return;
			}
			else
			{
				std::cout << "Couldn't create renderer" << std::endl;
				return;
			}
		}
		else
		{
			std::cout << "Couldn't create window" << std::endl;
			return;
		}
	}
	else
	{
		std::cout << "Couldn't initialize Subsystem" << std::endl;
		return;
	}
}

void Window::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
	{
		isRunning = false;
	}
}

void Window::update()
{
	cnt++;
}

void Window::beginRender()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

void Window::endRender()
{
	SDL_RenderPresent(renderer);
}

void Window::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game clean" << std::endl;
}
