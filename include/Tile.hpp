#ifndef TILE_HPP
#define TILE_HPP

class Tile
{
private:
	int x;
	int y;

public:
	bool hasMine = false;
	int number;
	bool isRevealed = false;
	bool isFlagged = false;

	Tile(bool hasMine);
	void setXY(int x, int y);

	int getX();
	int getY();
};

#endif
