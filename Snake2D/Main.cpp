#include <SDL.h>

#include "Window.h"
#include "Renderer.h"
#include "Game.h"

int main(int argc, char* argv[]) {

    Game::i().run();

	return 0;
}