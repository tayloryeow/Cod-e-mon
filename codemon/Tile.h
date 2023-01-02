#pragma once
#include "Coordinates.h"

class Tile
{
public:
	enum tile { long_grass = 1, short_grass = 0 };

	/* Constructors */
	Tile();
	Tile(unsigned int x, unsigned int y, Tile::tile data);
	Tile(Coordinates* tile_pos, Tile::tile data);
	
	/* Coordinate Getters*/
	unsigned int get_x();
	unsigned int get_y();
	Coordinates* get_pos();

	//Change and set tile position coordinate 
	void set_pos(unsigned int x, unsigned int y);

	/* Get what type of tile */
	Tile::tile get_data();

private:
	Coordinates *pos;
	Tile::tile data;
};

