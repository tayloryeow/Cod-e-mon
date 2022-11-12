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
	unsigned int start_x;
	unsigned int start_y;
	unsigned int tile_size;
	Coordinates size;


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
	bool in_bounds(Coordinates proposed_coord);
	unsigned int get_width();
	unsigned int get_height();
	unsigned int get_tile_size();
	Coordinates get_size();


};