#include "GameState.hpp"

GameState::GameState(int size, int mines) : field(size, mines)
{

};

// START GAME
void GameState::startGame()
{
	// init game state
	this->clicks = 0;

	// start timer
	this->startTimestamp = duration_cast<milliseconds>(
                                                       system_clock::now().time_since_epoch()
                                                       );

	// init field
	this->field = field;
	this->field.fillMines();
	this->field.calculateNumbers();
};

// ASK USER ACTION
void GameState::askUserAction()
{
    /*auto input;
    input << stdin;
    std::cout << input;*/
    
    std::string askedX = "A";
    std::string askedY = "6";
    std::string askedAction = "F";
    
    std::vector<std::string> alphabet = {"A", "B", "C", "D", "E", "F", "G", "H"};
    
    // find letter in alphabet
    int counter = 0;
    for(std::string letter : alphabet)
    {
        if(letter == askedX) break;
        counter++;
    }
    
    int actionX = counter;
    int actionY = std::atoi(askedY.c_str());
    
    this->field.applyAction(actionX, actionY, askedAction);
};

// END GAME
double GameState::endGame()
{
    milliseconds endTimestamp = duration_cast<milliseconds>(
                                                            system_clock::now().time_since_epoch()
                                                            );
    
    return (endTimestamp.count() - this->startTimestamp.count()) / 1000.0;
};
