#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include "Constants.h"

class Window
{
public:

	Window();
	~Window();

	SDL_Window* getWindow();

private:

	SDL_Window* window;
};

#endif