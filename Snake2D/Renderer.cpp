#include "Renderer.h"

Renderer::Renderer()
{
}

Renderer::Renderer(Window& window) : window(window)
{
	renderer = SDL_CreateRenderer(window.getWindow(), -1, SDL_RENDERER_ACCELERATED);

	if (renderer == nullptr) {
		SDL_Log("Error while creating the renderer: %s", SDL_GetError());
		SDL_Quit();
		return;
	}
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(renderer);
}

void Renderer::render(Snake& snake, Apple& apple, Button& tryAgainButton)
{
	SDL_SetRenderDrawColor(renderer, 0x10, 0x15, 0x1E, 0xFF);
	SDL_RenderClear(renderer);

	if (tryAgainButton.getIsVisible()) {
		renderButton(tryAgainButton);
	}
	else {
		renderSnake(snake);
		renderApple(apple);
	}

	SDL_RenderPresent(renderer);
}

void Renderer::renderSnake(Snake& snake)
{	
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	for (const SDL_Point& point : snake.getBody()) {
		int x = point.x;
		int y = point.y;

		SDL_Rect snakeRect = { x, y, POINT_SIZE, POINT_SIZE };
		SDL_RenderFillRect(renderer, &snakeRect);
	}
}

void Renderer::renderApple(Apple& apple)
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	int x = apple.getCoordinates().x;
	int y = apple.getCoordinates().y;

	SDL_Rect appleRect = { x, y, POINT_SIZE, POINT_SIZE };
	SDL_RenderFillRect(renderer, &appleRect);
}

void Renderer::renderButton(Button& button)
{
	button.render(renderer, 255, 0, 0);
}

SDL_Renderer* Renderer::getRenderer()
{
	return renderer;
}

void Renderer::updateWindowTitle(int score, std::chrono::high_resolution_clock::time_point startTime) {
	std::chrono::high_resolution_clock::time_point currentTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = currentTime - startTime;

	int minutes = static_cast<int>(elapsed.count()) / 60;
	int seconds = static_cast<int>(elapsed.count()) % 60;

	std::string timeText = (minutes < 10 ? "0" : "") + std::to_string(minutes) + ":" +
						   (seconds < 10 ? "0" : "") + std::to_string(seconds);
	std::string title = "Snake Score: " + std::to_string(score) + " Time passed: " + timeText;
	SDL_SetWindowTitle(window.getWindow(), title.c_str());
}
