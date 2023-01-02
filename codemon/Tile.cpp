#include "Tile.h"
#include <string>
#include "SFML/Graphics.hpp"

/* Constructors */
Tile::Tile(unsigned int x, unsigned int y, 	Tile::tile data) {
	this->pos = new Coordinates(x, y);
	this->data = data;	
}

//Todo add tile constructor off of a coordinate not just naked coord ints
Tile::Tile(Coordinates *tile_pos, Tile::tile data) {
	this->pos = tile_pos;
	this->data = data;
}


Tile::Tile() {
	this->pos = new Coordinates(0, 0);
	this->data = (Tile::tile) 0;
}


unsigned int Tile::get_x()
{
	return this->get_pos()->get_x();
}


unsigned int Tile::get_y()
{
	return this->get_pos()->get_y();
}

Tile::tile Tile::get_data()
{
	return this->data;
}

Coordinates* Tile::get_pos() {
	return this->pos;
}


void Tile::set_pos(unsigned int x, unsigned int y) {
	this->get_pos()->set_x(x);
	this->get_pos()->set_y(y);
}
