#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include "Snake.h"
#include "Apple.h"
#include "Controller.h"
#include "Window.h"
#include "Renderer.h"
#include "Constants.h"
#include "GameState.h"
#include "Button.h"

class Game
{
public:

	static Game& i();
	Game(Game const&) = delete;
	void operator=(Game const&) = delete;

	~Game();

	void run();

private:

	Game();

	Controller controller;
	Window window;
	Renderer renderer = Renderer(window);
	Snake snake = Snake(80, 80, 50);
	Apple apple;
	Button tryAgainBtn = Button(std::bind(&Game::tryAgain, this));

	int steps = 0;
	int applesEaten = 0;

	std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();

	GameState gameState = GameState::PLAYING;
	Direction lastDirection = Direction::UP;

	void moveTo(Direction direction);
	void checkCollisions();
	void placeApple();
	void handleGameOverState();
	void handlePlayingState();
	void tryAgain();

	bool isSpaceEmpty();
	bool isDirrectionInvalid(Direction direction);
};

#endif