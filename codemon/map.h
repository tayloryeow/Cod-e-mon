#pragma once
#include <string>
#include <fstream>

#include "tile.h"
#include "SFML/Graphics.hpp"


class map
{
private:
	unsigned int width;
	unsigned int height;
	unsigned int start_x;
	unsigned int start_y;

	sf::Texture map_sheet;

	std::string map_path;
	std::string sheet_path;
	Tile::tile* tile_map[];
	map(std::string map_path, std::string sheet_path);
public:
	Tile::tile** get_map();
	sf::Texture* render_map();
};