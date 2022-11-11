#pragma once


class Tile
{
public:
	enum tile { long_grass = 0, short_grass = 1 };
	Tile(unsigned int x, unsigned int y, Tile::tile data);
private:
	unsigned int x;
	unsigned int y;
	Tile::tile data;
};

