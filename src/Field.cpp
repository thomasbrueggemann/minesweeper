#include "Field.hpp"

// CONSTRUCTOR
Field::Field(int size, int mines)
{
	this->size = size;
	this->mines = mines;

	// fill the field matrix with size-appropriate false values
	for(int x = 0; x < size; x++)
	{
		std::vector<Tile> inner;

		for(int y = 0; y < size; y++)
		{
			// init tile with no mine
			Tile tile(false);
			tile.setXY(x, y);

			inner.push_back(tile);
		}

		this->matrix.push_back(inner);
	}
};

// FILL MINES
void Field::fillMines()
{
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, this->size - 1);

	// create m mines randomly
	for(int m = 0; m < this->mines; m++)
	{
		int x = (int)dis(gen);
		int y = (int)dis(gen);

		// if this tile is already in use, skip ahead
		if(this->matrix[x][y].hasMine == true)
		{
			m--;
			continue;
		}

		this->matrix[x][y].hasMine = true;
	}
};

// CALCULATE NUMBERS
void Field::calculateNumbers()
{
    // loop row and columns by reference to be able to alter values
	for(auto &outer : this->matrix)
	{
		for(auto &inner : outer)
		{
            inner.number = this->calculateNumber(inner);
		}
	}
};

// CALCULATE NUMBER
int Field::calculateNumber(Tile tile)
{
    if(tile.hasMine == true)
    {
        return 0;
    }
    
    // get the neighbors of the tile
    std::vector<Tile> neighbors = this->getNeighbors(tile);
    int numMinesInNeighbors = 0;
    
    // find out how many mines are adjacent
    for(Tile neighborTile : neighbors)
    {
        if(neighborTile.hasMine == true)
        {
            numMinesInNeighbors++;
        }
    }
    
    return numMinesInNeighbors;
};

// PRINT MINES
void Field::printMines()
{
	for(auto outer : this->matrix)
	{
		for(auto inner : outer)
		{
			if(inner.hasMine == true) std::cout << "1 ";
			if(inner.hasMine == false) std::cout << "0 ";
		}

		std::cout << std::endl;
	}
};

// PRINT NUMBERS
void Field::printNumbers()
{
	for(auto outer : this->matrix)
	{
		for(auto inner : outer)
		{
            if(inner.hasMine) std::cout << "* ";
			else std::cout << std::to_string(inner.number) + " ";
		}

		std::cout << std::endl;
	}
};

// PRINT FIELD
void Field::printField()
{
    system("clear");
    
    std::cout << "   A B C D E F G H" << std::endl;
    std::cout << "   ---------------" << std::endl;
    
    int counter = 1;
    for(auto outer : this->matrix)
    {
        std::cout << counter << "| ";
        
        for(auto inner : outer)
        {
            if(inner.isRevealed == false && inner.isFlagged == false) std::cout << "?";
            if(inner.isRevealed == false && inner.isFlagged == true) std::cout << "F";
            if(inner.isRevealed == true && inner.hasMine == true) std::cout << "*";
            if(inner.isRevealed == true && inner.hasMine == false) std::cout << inner.number;
            
            std::cout << " ";
        }
        
        counter++;
        std::cout << std::endl;
    }
};

// GET NEIGHBORS
std::vector<Tile> Field::getNeighbors(Tile tile)
{
	return this->getNeighbors(tile.getX(), tile.getY());
};

// GET NEIGHBORS
std::vector<Tile> Field::getNeighbors(int x, int y)
{
	std::vector<Tile> neighbors;

	// find the x field before and after the search position and respect the
	// field bounds
	for(int nX = x - 1; nX <= x + 1; nX++)
	{
		// find the y field before and after the search position and respect
		// the field bounds
		for(int nY = y - 1; nY <= y + 1; nY++)
		{
			// do not include the x/y search tile itself
			if((nX != x || nY != y) && nX >= 0 && nX < this->size && nY >= 0 && nY < this->size)
			{
				neighbors.push_back(this->matrix[nX][nY]);
			}
		}
	}

	return neighbors;
};

// REVEAL TILES
RevealResult Field::revealTiles(Tile clickedTile)
{
	RevealResult result;

	// check for mine hit that has not been revealed before
	if(clickedTile.hasMine == true && clickedTile.isRevealed == false)
	{
		result.hitMine = true;
		return result;
	}

	// check for a click on a tile that has already been revealed before
	if(clickedTile.isRevealed == true)
	{
		result.alreadyReveled = true;
		return result;
	}

	// check if the clicked tile is already flagged and therefore not clickable
	if(clickedTile.isFlagged == true)
	{
		result.alreadyFlagged = true;
		return result;
	}
    
    // a non revealed mine is found in the adjacent tiles of
    // the neighbor
    if(clickedTile.hasMine == false && clickedTile.isRevealed == false && clickedTile.number == 0)
    {
        clickedTile.isRevealed = true;
    }

	// find all tiles that are adjecent to the clicked tile
	// that have a number value of 0, recursively
	std::vector<Tile> neighbors = this->getNeighbors(clickedTile);
	for(auto &tile : neighbors)
	{
        //this->revealTiles(tile);
	}

	result.ok = true;
	return result;
};

// FLAG TILE
FlagResult Field::flagTile(Tile tile)
{
	FlagResult result;

	// check if this tile is already revealed and cannot be flagged
	if(tile.isRevealed == true)
	{
		result.alreadyRevealed = true;
		return result;
	}

	tile.isFlagged = !tile.isFlagged;

	result.ok = true;
	return result;
};

// APPLY ACTION
void Field::applyAction(int x, int y, std::string action)
{
    // fetch the action tile
    Tile t = this->matrix[x][y];
    
    // flag
    if(action == "F")
    {
        this->flagTile(t);
    }
    
    // reveal
    if(action == "R")
    {
        this->revealTiles(t);
    }
};
