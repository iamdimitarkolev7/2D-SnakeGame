#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SDL.h>
#include "Direction.h"

class Controller
{
public:

    Controller();
    ~Controller();

    void processInput();
    Direction getDirection();

    bool getIsRunning();
    void setIsRunning(bool isRunning);

private:

    Direction direction;
    bool isRunning = true;

    void handleKeyPress(SDL_Keycode key);
};

#endif