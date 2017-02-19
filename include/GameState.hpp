#ifndef STATE_HPP
#define STATE_HPP

#include <chrono>
#include <algorithm>

#include "Field.hpp"

using namespace std::chrono;

class GameState
{
public:
	int clicks;
	int minesLeft;
	milliseconds startTimestamp;
	Field field;

	GameState(int size, int mines);
	void startGame();
    double endGame();
    void REPL();
    
    void askUserAction();
};

#endif
