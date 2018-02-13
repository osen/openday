#ifndef UTIL_H
#define UTIL_H

#include <SDL/SDL.h>

#include <string>

namespace util
{
	extern SDL_Window* sdl_window;
	extern SDL_Surface* sdl_screen;
	extern bool should_exit;

	void sdl_initialize(std::string title, int width, int height);
	void sdl_poll();
	void sdl_clearscreen(int r, int g, int b);
	void sdl_blit(SDL_Surface* src, int x, int y);

	void error(std::string message);

}

#endif