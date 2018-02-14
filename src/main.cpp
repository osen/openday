#include "util.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

SDL_Surface* image;
SDL_Surface* icon;
util::Spritesheet* ss;
int dir;
int anim;
int jump;
float y;

void on_load()
{
	image = IMG_Load("resources/player.png");
	if (!image) util::error("Failed to load image");

	icon = IMG_Load("resources/icon.png");
	if (!icon) util::error("Failed to load icon");

	ss = util::SpritesheetLoad("resources/player_ss.png", 4, 4);
	if (!ss) util::error("Failed to load spritesheet");
}

void on_update()
{
	anim = 0;
	if (util::sdl_keydown(SDLK_RIGHT))
	{
		std::cout << "I should move right" << std::endl;
		dir = 0;
		anim = 2;
	}
	if (util::sdl_keydown(SDLK_LEFT))
	{
		std::cout << "I should move left" << std::endl;
		dir = 1;
		anim = 2;
	}

	if (util::sdl_keydown(SDLK_UP))
	{
          jump = 1;
	}

	if(jump == 1)
	{
		y -= 500 * util::delta_time;

		if(y < -200) jump = 2;
	}
	else if(jump == 2)
	{
		y += 500 * util::delta_time;

		if(y > 0) jump = 0;
	}
}

void on_draw()
{
	util::sdl_clearscreen(254, 222, 0);

	static float frame = 0;

	//util::sdl_blit(image, util::sdl_screen, 200, 200);
	util::SpritesheetBlit(ss, frame, anim + dir, util::sdl_screen, 200, 200 + y);

	frame += util::delta_time * 5;

	SDL_UpdateWindowSurface(util::sdl_window);
}

void on_cleanup()
{
	SDL_FreeSurface(image);
	SDL_FreeSurface(icon);
	util::SpritesheetFree(ss);
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
		SDL_Delay(5);
	}

	on_cleanup();

	return 0;
}
