#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>
#include <string>
#include <functional>
#include "Constants.h"

class Button 
{
public:

    Button(std::function<void()> onClick);

    void render(SDL_Renderer* renderer, Uint8 red, Uint8 green, Uint8 blue);
    void handleClick();

    bool isMouseOver(int mouseX, int mouseY) const;

    void setIsVisible(bool isVisible);
    bool getIsVisible();

private:

    int x = BUTTON_X;
    int y = BUTTON_Y;
    int width = BUTTON_WIDTH;
    int height = BUTTON_HEIGHT;
    bool isVisible = false;
    std::function<void()> onClick;
};

#endif