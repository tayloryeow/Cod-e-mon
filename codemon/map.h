#pragma once
#include <string>
#include <fstream>

#include "tile.h"
#include "Window.h"
#include "SFML/Graphics.hpp"



class Map
{
private:
	unsigned int width;
	unsigned int height;
	unsigned int start_x;
	unsigned int start_y;

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

};