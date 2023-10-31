#include "Controller.h"

Controller::Controller() {}

Controller::~Controller() {}

void Controller::processInput()
{
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            isRunning = false;
        }
        else if (e.type == SDL_KEYDOWN) {
            handleKeyPress(e.key.keysym.sym);
        }
    }
}

Direction Controller::getDirection()
{
    return direction;
}

bool Controller::getIsRunning()
{
    return this->isRunning;
}

void Controller::setIsRunning(bool isRunning)
{
    this->isRunning = isRunning;
}

void Controller::handleKeyPress(SDL_Keycode key)
{
    switch (key) {
        case SDLK_UP:
            direction = Direction::UP;
            break;
        case SDLK_DOWN:
            direction = Direction::DOWN;
            break;
        case SDLK_LEFT:
            direction = Direction::LEFT;
            break;
        case SDLK_RIGHT:
            direction = Direction::RIGHT;
            break;
        case SDLK_RETURN:
            break;
    }
}
