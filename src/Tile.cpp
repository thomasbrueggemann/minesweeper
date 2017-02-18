#include "Tile.hpp"

// CONSTRUCTOR
Tile::Tile(bool hasMine)
{
	this->hasMine = hasMine;
};

// SET XY
void Tile::setXY(int x, int y)
{
	this->x = x;
	this->y = y;
};

// GET X
int Tile::getX()
{
	return this->x;
};

// GET Y
int Tile::getY()
{
	return this->y;
};
