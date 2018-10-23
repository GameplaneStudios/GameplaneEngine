#include "Engine/Graphics/Window.h"
#include "Engine/Object.h"
#include "Engine/Graphics/Sprite.h"

Window* window = NULL;

int main(int argc, char* argv[])
{
	const int fps = 60;
	const float frameDelay = 1000.0f / fps;
	Uint32 frameStart;
	int frameTime;

	window = new Window();
	window->init("Gameplane Engine", 800, 600);

	

	while (window->running())
	{
		frameStart = SDL_GetTicks();

		window->handleEvents();
		window->update();
		window->beginRender();
		#pragma region Render Stuff

		#pragma endregion
		window->endRender();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) { SDL_Delay((Uint32)(frameDelay - frameTime)); }
	}

	window->clean();

	return 0;
}
