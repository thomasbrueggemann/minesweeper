#include "Field.hpp"

// CONSTRUCTOR
Field::Field(unsigned int size, unsigned int mines)
{
	this->size = size;
	this->mines = mines;

	// fill the field matrix with size-appropriate false values
	for(unsigned int x = 0; x < size; x++)
	{
		std::vector<Tile> inner;

		for(unsigned int y = 0; y < size; y++)
		{
			// init tile with no mine
			Tile tile(false);
			tile.SetXY(x, y);

			inner.push_back(tile);
		}

		this->matrix.push_back(inner);
	}
};

// FILL MINES
void Field::FillMines()
{
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, this->size);

	// create m mines randomly
	for(unsigned int m = 0; m < this->mines; m++)
	{
		unsigned int x = (unsigned int)dis(gen);
		unsigned int y = (unsigned int)dis(gen);

		// if this tile is already in use, skip ahead
		if(this->matrix[x][y].HasMine() == true)
		{
			m--;
			continue;
		}

		this->matrix[x][y].SetMine(true);
	}
};

// PRINT
void Field::Print()
{
	for(auto outer : this->matrix)
	{
		for(auto inner : outer)
		{
			if(inner.HasMine() == true) std::cout << "1 ";
			if(inner.HasMine() == false) std::cout << "0 ";
		}

		std::cout << std::endl;
	}
};

// GET NEIGHBORS
std::vector<Tile> Field::GetNeighbors(Tile tile)
{
	return this->GetNeighbors(tile.GetX(), tile.GetY());
};

// GET NEIGHBORS
std::vector<Tile> Field::GetNeighbors(unsigned int x, unsigned int y)
{
	std::vector<Tile> neighbors;

	// find the x field before and after the search position and respect the field bounds
	for(unsigned int nX = std::max(x - 1, 0); nX < std::min(x + 1, this->size); nX++)
	{
		// find the y field before and after the search position and respect the field bounds
		for(unsigned int nY = std::max(y - 1, 0); nY < std::min(y + 1, this->size); nY++)
		{
			// do not include the x/y search tile itself
			if(nX != x && nY != y)
			{
				neighbors.push_back(this->matrix[nX][nY]);
			}
		}
	}

	return neighbors;
};
