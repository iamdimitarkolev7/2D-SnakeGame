#include "Window.h"

Window::Window()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("SDL_Init Error: %s", SDL_GetError());
        return;
    }

    window = SDL_CreateWindow("Snake 2D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
        WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);

    if (window == nullptr) {
        SDL_Log("SDL_CreateWindow Error: %s", SDL_GetError());
        SDL_Quit();
        return;
    }
}

Window::~Window()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}

SDL_Window* Window::getWindow()
{
	return this->window;
}
