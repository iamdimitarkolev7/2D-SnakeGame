#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>
#include <string>
#include <chrono>
#include <iomanip>
#include "Window.h"
#include "Snake.h"
#include "Apple.h"
#include "Button.h"
#include "Constants.h"

class Renderer
{
public:

	Renderer();
	Renderer(Window& window);
	~Renderer();

	void render(Snake& snake, Apple& apple, Button& tryAgainButton);
	void renderSnake(Snake& snake);
	void renderApple(Apple& apple);
	void renderButton(Button& button);

	SDL_Renderer* getRenderer();
	void updateWindowTitle(int score, std::chrono::high_resolution_clock::time_point startTime);

private:

	SDL_Renderer* renderer;
	Window window;
};

#endif