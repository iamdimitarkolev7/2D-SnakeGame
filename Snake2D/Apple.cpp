#include "Apple.h"

Apple::Apple()
{
    coordinates = SDL_Point{ 50, 50 };
}

Apple::~Apple() {}

SDL_Point Apple::getCoordinates()
{
    return coordinates;
}

void Apple::setCoordinates(SDL_Point coordinates)
{
    this->coordinates = coordinates;
}
