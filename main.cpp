#include <iostream>
#include <SDL/SDL.h>
#include "Game.h"

int main(int argc, char* argv[]) {
	Game *game = new Game();
	game->startGame();

	return 0;
}
