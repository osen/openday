#include "util.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

SDL_Surface* image;

void on_load()
{
	image = IMG_Load("resources/hello_world.bmp");

	if (!image)
	{
		util::error("Failed to load image");
	}
}

void on_update()
{
	
}

void on_draw()
{
	util::sdl_clearscreen(254, 222, 0);

	SDL_BlitSurface(image, NULL, util::sdl_screen, NULL);

	SDL_UpdateWindowSurface(util::sdl_window);
	SDL_Delay(100);
}

void on_cleanup()
{
	SDL_FreeSurface(image);
}

int main(int argc, char* args[])
{
	util::sdl_initialize("Introduction Game (C++/SDL)", 800, 600);

	on_load();	

	while (!util::should_exit)
	{
		util::sdl_poll();
		on_update();
		on_draw();
	}

	on_cleanup();

	return 0;
}