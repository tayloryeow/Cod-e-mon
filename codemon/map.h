#pragma once
#include <string>
#include <fstream>

#include "tile.h"
#include "Window.h"
#include "SFML/Graphics.hpp"
#include "direction.h"
#include "character.h"
#include "Coordinates.h"



class Map
{
private:
	Coordinates dimensions;
	Coordinates start_pos;

	sf::Texture map_sheet;

	std::string map_path;
	std::string sheet_path;
	//2d array of tile pointers
	Tile* tile_map;

	void add_tile(Tile *new_tile);

public:
	Tile* get_map();
	Map(std::string map_path, std::string sheet_path);
	void render_map(Window *active_window);
	bool in_bounds(Character *moving_char, DIR move_dir);
	bool in_bounds(Coordinates proposed_coord);
	void set_width(unsigned int width);
	void set_height(unsigned int height);
	unsigned int get_width();
	unsigned int get_height();
	Coordinates *get_dimensions();
	void set_dimensions(Coordinates start);
	void set_start_pos(Coordinates start);
	Coordinates get_start_pos();

};