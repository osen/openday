#ifndef UTIL_H
#define UTIL_H

#include <SDL2/SDL.h>

#include <string>

namespace util
{
	extern SDL_Window* sdl_window;
	extern SDL_Surface* sdl_screen;
	extern bool should_exit;
	extern double delta_time;

	void sdl_initialize(std::string title, int width, int height);
	void sdl_poll();
	void sdl_clearscreen(int r, int g, int b);
	void sdl_blit(SDL_Surface* src, int x, int y);
	bool sdl_keydown(SDL_Keycode key);

	void error(std::string message);
}

#endif
