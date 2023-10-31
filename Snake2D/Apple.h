#ifndef APPLE_H
#define APPLE_H

#include <SDL.h>
#include <random>
#include "Snake.h"

class Apple
{
public:
	
	Apple();
	~Apple();

	SDL_Point getCoordinates();
	void setCoordinates(SDL_Point coordinates);

private:

	SDL_Point coordinates;
};

#endif