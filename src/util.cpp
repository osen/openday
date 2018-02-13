#include "util.h"

#include <windows.h>

#include <iostream>

namespace util
{
	SDL_Window* sdl_window;
	SDL_Surface* sdl_screen;
	bool should_exit;

	void log(std::string message)
	{
		std::cout << "[util]" << message << std::endl;
	}

	void cleanup()
	{
		log("Cleaning up SDL2");
		SDL_DestroyWindow(sdl_window);
		SDL_Quit();
	}

	void error(std::string message)
	{
		std::cout << "Error: " << message << std::endl;
		MessageBox(0, message.c_str(), "SDL Program Error", 0);
		exit(1);
	}

	void sdl_initialize(std::string title, int width, int height)
	{
		log("Initializing SDL2");

		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			error("Failed to initialize SDL");
		}

		sdl_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

		if (!sdl_window)
		{
			error("Failed to open window");
		}

		sdl_screen = SDL_GetWindowSurface(sdl_window);
		atexit(cleanup);
	}

	void sdl_poll()
	{
		SDL_Event e = { 0 };

		while (SDL_PollEvent(&e) != 0)
		{
			if( e.type == SDL_QUIT )
			{
				should_exit = true;
			}
		}
	}

	void sdl_clearscreen(int r, int g, int b)
	{
		SDL_FillRect(sdl_screen, &sdl_screen->clip_rect, SDL_MapRGB(sdl_screen->format, r, g, b));
	}

	void sdl_blit(SDL_Surface* src, int x, int y)
	{
		SDL_Rect r = { 0 };
		r.x = x;
		r.y = y;
		SDL_BlitSurface(src, NULL, util::sdl_screen, &r);
	}

	bool sdl_keydown(SDL_Keycode key)
	{
		const Uint8* state = SDL_GetKeyboardState(NULL);

		if (state[(Uint8)key]) return true;
		return false;
	}

}