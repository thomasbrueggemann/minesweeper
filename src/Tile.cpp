#include "Tile.hpp"

// CONSTRUCTOR
Tile::Tile(bool hasMine)
{
	this->SetMine(hasMine);
};

// SET MINE
void Tile::SetMine(bool hasMine)
{
	this->hasMine = hasMine;
};

// HAS MINE
bool Tile::HasMine()
{
	return this->hasMine;
};

// SET XY
void Tile::SetXY(unsigned int x, unsigned int y)
{
	this->x = x;
	this->y = y;
};

// GET X
unsigned int Tile::GetX()
{
	return this->x;
};

// GET Y
unsigned int Tile::GetY()
{
	return this->y;
};
