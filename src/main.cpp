#include <iostream>
#include <cstdlib>

#include "GameState.hpp"

// MAIN
int main()
{
	GameState state(8, 10);
	state.startGame();
    state.REPL();
	
    std::cout << state.endGame() << "s" << std::endl;

	return EXIT_SUCCESS;
};
