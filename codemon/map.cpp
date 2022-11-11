#include "map.h"

Tile::tile** map::get_map()
{
    return this->tile_map;
}

//Return a texture rendered from get_map();
sf::Texture* map::render_map()
{
    return nullptr;
}

map::map(std::string map_path, std::string sheet_path){
    this->map_path = map_path;
    this->sheet_path = sheet_path;
    std::fstream mapfile;

    //Load the sprite sheet for this map.
    if (!this->map_sheet.loadFromFile(this->sheet_path, sf::IntRect(10, 10, 32, 32)))
    {
        // error...
    }

    //Load map bin data
    mapfile.open(this->map_path, std::ios::in);
    if (mapfile.is_open()) {
        std::string new_row;
        while (getline(mapfile, new_row));
    }
    mapfile.close();


}
