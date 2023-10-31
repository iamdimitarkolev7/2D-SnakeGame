#include "Game.h"

Game::Game()
{
	placeApple();
}

void Game::moveTo(Direction direction)
{
	if (!snake.getIsAlive()) {
		return;
	}

	snake.move(direction);
}

void Game::checkCollisions()
{
	// Check if the snake collapsed in itself
	if (snake.checkSelfCollision()) {
		gameState = GameState::GAME_OVER;
		tryAgainBtn.setIsVisible(true);
		return;
	}

	// Check if the snake collapsed in an apple
	SDL_Point snakeHead = snake.getHead();
	SDL_Point appleCoordinates = apple.getCoordinates();

	if (abs(appleCoordinates.x - snakeHead.x) < 10 && abs(appleCoordinates.y - snakeHead.y) < 10) {
		applesEaten++;
		snake.grow();
		placeApple();

		if (applesEaten % 3 == 0) {
			steps++;
		}
	}
}

void Game::placeApple()
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> xDistribution(0, 1280);
	std::uniform_int_distribution<int> yDistribution(0, 720);

	do {
		int x = xDistribution(gen);
		int y = yDistribution(gen);
		apple.setCoordinates(SDL_Point{x, y});
	} while (!isSpaceEmpty());
}

void Game::handleGameOverState()
{
	SDL_Event e;

	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_QUIT) {
			controller.setIsRunning(false);
		}
		else if (e.type == SDL_MOUSEBUTTONDOWN) {
			int mouseX = e.button.x;
			int mouseY = e.button.y;

			if (e.button.button == SDL_BUTTON_LEFT && tryAgainBtn.isMouseOver(mouseX, mouseY)) {
				tryAgainBtn.handleClick();
			}
		}
	}
}

void Game::handlePlayingState()
{
	controller.processInput();
	Direction currentDirection = controller.getDirection();

	// preventing unwanted behaviour; Ex: snake is not supposed to move to the LEFT if its direction is to the RIGHT
	if (isDirrectionInvalid(currentDirection)) {
		moveTo(lastDirection);
	}
	else {
		moveTo(currentDirection);
		lastDirection = currentDirection;
	}

	checkCollisions();
}

void Game::tryAgain()
{
	gameState = GameState::PLAYING;
	tryAgainBtn.setIsVisible(false);
	snake = Snake(80, 80, 50);
	placeApple();
	startTime = std::chrono::high_resolution_clock::now();
	applesEaten = 0;
	steps = 0;
}

bool Game::isSpaceEmpty()
{
	const auto& snakeBody = snake.getBody();

	for (const auto& part : snakeBody) {
		if (part.x == apple.getCoordinates().x && part.y == apple.getCoordinates().y) {
			return false;
		}
	}

	return true;
}

bool Game::isDirrectionInvalid(Direction direction)
{
	return lastDirection == direction ||
		(lastDirection == Direction::UP && direction == Direction::DOWN) ||
		(lastDirection == Direction::DOWN && direction == Direction::UP) ||
		(lastDirection == Direction::LEFT && direction == Direction::RIGHT) ||
		(lastDirection == Direction::RIGHT && direction == Direction::LEFT);
}

Game& Game::i()
{
	static Game instance;
	return instance;
}

Game::~Game()
{
}

void Game::run()
{
	while (controller.getIsRunning()) {

		if (gameState == GameState::GAME_OVER) {
			handleGameOverState();
			continue;
		}
		else {
			handlePlayingState();
		}

		renderer.render(snake, apple, tryAgainBtn);
		renderer.updateWindowTitle(applesEaten, startTime);

		int delay = INITIAL_DELAY - (steps * 5);
		
		if (delay < 0) {
			SDL_Delay(1);
		}
		else {
			SDL_Delay(delay);
		}
	}
}
