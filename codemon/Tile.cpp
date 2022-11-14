#include "Tile.h"
#include <string>
#include "SFML/Graphics.hpp"

Tile::Tile(unsigned int x, unsigned int y, 	Tile::tile data) {
	this->x = x;
	this->y = y;
	this->data = data;	
}

Tile::Tile() {
	this->x = 0;
	this->y = 0;
	this->data = (Tile::tile) 0;
}


unsigned int Tile::get_x()
{
	return this->x;
}


unsigned int Tile::get_y()
{
	return this->y;
}

Tile::tile Tile::get_data()
{
	return this->data;
}
