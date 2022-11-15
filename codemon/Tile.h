#pragma once
#include "Coordinates.h"

class Tile
{
public:
	enum tile { long_grass = 1, short_grass = 0 };
	Tile(unsigned int x, unsigned int y, Tile::tile data);
	Tile();
	unsigned int get_x();
	unsigned int get_y();
	Tile::tile get_data();
	Coordinates* get_pos();
	void set_pos(unsigned int x, unsigned int y);
private:
	Coordinates *pos;
	Tile::tile data;
};

