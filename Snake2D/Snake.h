#ifndef SNAKE_H
#define SNAKE_H

#include <SDL.h>
#include <deque>
#include <cstdlib>
#include "Direction.h"
#include "Constants.h"

class Snake
{
public:

	Snake();
	Snake(int startX, int startY, int initialSize);
	~Snake();

	void move(Direction direction);
	std::deque<SDL_Point>& getBody();
	SDL_Point getHead();
	void grow();
	bool checkSelfCollision();

	bool getIsAlive();
	void setIsAlive(bool isAlive);

private:

	std::deque<SDL_Point> body;
	bool isAlive = true;
};

#endif