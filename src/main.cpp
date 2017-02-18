#include <iostream>
#include <cstdlib>

#include "GameState.hpp"

// MAIN
int main()
{
	GameState state(8, 10);
	state.startGame();

	std::cout << std::endl;

	state.field.printField();
    std::cout << state.endGame() << "s" << std::endl;

	return EXIT_SUCCESS;
};
