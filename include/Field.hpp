#ifndef FIELD_HPP
#define FIELD_HPP

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

#include "Tile.hpp"

typedef std::vector< std::vector<Tile> > Matrix;

class Field
{
private:
	Matrix matrix;
	unsigned int size;
	unsigned int mines;

public:
	Field(unsigned int size, unsigned int mines);
	void FillMines();
	void Print();

	std::vector<Tile> GetNeighbors(Tile tile);
	std::vector<Tile> GetNeighbors(unsigned int x, unsigned int y)
};

#endif
