#include "Snake.h"

Snake::Snake() {}

Snake::Snake(int startX, int startY, int initialSize)
{
    for (int i = 0; i < initialSize; i++) {
        body.push_back(SDL_Point{ startX + i, startY });
    }
}

Snake::~Snake()
{
}

void Snake::move(Direction direction)
{
    int dx = body.front().x;
    int dy = body.front().y;

    switch (direction) {
        case Direction::UP:
            dy = (dy - 1 + WINDOW_HEIGHT) % WINDOW_HEIGHT;
            break;
        case Direction::DOWN:
            dy = (dy + 1) % WINDOW_HEIGHT;
            break;
        case Direction::LEFT:
            dx = (dx - 1 + WINDOW_WIDTH) % WINDOW_WIDTH;
            break;
        case Direction::RIGHT:
            dx = (dx + 1) % WINDOW_WIDTH;
            break;
    }

    body.push_front(SDL_Point{ dx, dy });
    body.pop_back();
}

std::deque<SDL_Point>& Snake::getBody()
{
    return body;
}

SDL_Point Snake::getHead()
{
    return body.front();
}

void Snake::grow()
{
    SDL_Point tail = body.back();

    for (int i = 0; i < 50; i++) {
        body.push_back(tail);
    }
}

bool Snake::getIsAlive()
{
    return this->isAlive;
}

void Snake::setIsAlive(bool isAlive)
{
    this->isAlive = isAlive;
}

bool Snake::checkSelfCollision() {
    const auto& head = body.front();

    for (auto it = body.begin() + 1; it != body.end(); ++it) {
        if (it->x == head.x && it->y == head.y) {
            return true;
        }
    }

    return false;
}