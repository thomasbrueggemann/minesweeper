#ifndef FIELD_HPP
#define FIELD_HPP

#include <iostream>
#include <vector>
#include <random>
#include <stdlib.h>

#include "Tile.hpp"
#include "RevealResult.hpp"
#include "FlagResult.hpp"

typedef std::vector< std::vector<Tile> > Matrix;

class Field
{
private:
	Matrix matrix;
	int size;
	int mines;

public:
	Field(int size, int mines);
	void fillMines();
    FlagResult flagTile(Tile &tile);
    void applyAction(int x, int y, std::string action);
    
    int calculateNumber(Tile tile);
	void calculateNumbers();
    
	RevealResult revealTiles(Tile &fromTile);
    RevealResult revealTiles(Tile &clickedTile, std::vector<Tile> &visited);

    void printField();
	void printMines();
	void printNumbers();

	std::vector<Tile> getNeighbors(Tile tile);
	std::vector<Tile> getNeighbors(int x, int y);
};

#endif
