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
    
    std::cout << "Column [A-H]: ";
    std::cin >> askedX;
    std::transform(askedX.begin(), askedX.end(), askedX.begin(), ::toupper);
    
    std::cout << "Row [1-8]: ";
    std::cin >> askedY;
    
    std::cout << "Action [F, R]: ";
    std::cin >> askedAction;
    std::transform(askedAction.begin(), askedAction.end(), askedAction.begin(), ::toupper);
    
    std::vector<std::string> alphabet = {"A", "B", "C", "D", "E", "F", "G", "H"};
    
    // find letter in alphabet
    int counter = 0;
    for(std::string letter : alphabet)
    {
        if(letter == askedX) break;
        counter++;
    }
    
    int actionX = counter;
    int actionY = std::atoi(askedY.c_str()) - 1;
    
    this->field.applyAction(actionX, actionY, askedAction);
};

// REPL
void GameState::REPL()
{
    while(true)
    {
        this->field.printField();
        this->askUserAction();
    }
};

// END GAME
double GameState::endGame()
{
    milliseconds endTimestamp = duration_cast<milliseconds>(
                                                            system_clock::now().time_since_epoch()
                                                            );
    
    return (endTimestamp.count() - this->startTimestamp.count()) / 1000.0;
};
