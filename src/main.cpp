#include "util.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include <iostream>

SDL_Surface* image;
SDL_Surface* icon;

void on_load()
{
	image = IMG_Load("resources/player.png");
	if (!image) util::error("Failed to load image");

	icon = IMG_Load("resources/icon.png");
	if (!icon) util::error("Failed to load icon");
}

void on_update()
{
	if (util::sdl_keydown(SDLK_RIGHT))
	{
		std::cout << "I should move right" << std::endl;
	}
}

void on_draw()
{
	util::sdl_clearscreen(254, 222, 0);

	util::sdl_blit(image, 200, 200);

	SDL_UpdateWindowSurface(util::sdl_window);
}

void on_cleanup()
{
	SDL_FreeSurface(image);
	SDL_FreeSurface(icon);
}

int main(int argc, char* args[])
{
	util::sdl_initialize("Introduction Game (C++/SDL)", 800, 600);

	on_load();
	SDL_SetWindowIcon(util::sdl_window, icon);

	while (!util::should_exit)
	{
		util::sdl_poll();
		on_update();
		on_draw();
		SDL_Delay(50);
	}

	on_cleanup();

	return 0;
}