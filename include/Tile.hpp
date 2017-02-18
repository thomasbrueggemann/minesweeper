#ifndef TILE_HPP
#define TILE_HPP

class Tile
{
private:
	bool hasMine = false;
	bool isFlagged = false;
	unsigned int x;
	unsigned int y;

public:
	Tile(bool hasMine);
	void SetMine(bool hasMine);
	bool HasMine();
	void SetXY(unsigned int x, unsigned int y);
	unsigned int GetX();
	unsigned int GetY();
};

#endif
