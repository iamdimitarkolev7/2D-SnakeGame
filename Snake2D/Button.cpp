#include "Button.h"

Button::Button(std::function<void()> onClick) : onClick(onClick) {}

void Button::render(SDL_Renderer* renderer, Uint8 red, Uint8 green, Uint8 blue)
{
    if (!isVisible) return;

    SDL_SetRenderDrawColor(renderer, red, green, blue, 255);

    SDL_Rect buttonRect = { x, y, width, height };
    SDL_RenderFillRect(renderer, &buttonRect);

    SDL_RenderPresent(renderer);
}

bool Button::isMouseOver(int mouseX, int mouseY) const
{
    return mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height;
}

void Button::handleClick()
{
	if (onClick) {
		onClick();
	}
}

void Button::setIsVisible(bool isVisible)
{
    this->isVisible = isVisible;
}

bool Button::getIsVisible()
{
    return isVisible;
}
