#include "map.h"
#include "Tile.h"
#include "Window.h"
#include <string>
#include <sstream>
#include <iostream>



void Map::add_tile(Tile *new_tile)
{
    this->tile_map[new_tile->get_x() + new_tile->get_y() *this->width] = *new_tile;
}

Tile* Map::get_map()
{
    return this->tile_map;
}

//Return a texture rendered from get_map();
//This only works because each tilesheet is constructed such that its enum value is its position in the 
//tile sheet row
void Map::render_map(Window *active_window)
{

    //Get the spritesheet read to sample from
    sf::Sprite to_draw(this->map_sheet);
    //Read through tile_map and render each tile
    for (unsigned int y = 0; y < this->height; y++){             //Each row
        for (unsigned int x = 0; x < this->width; x++) {         //Each column in each row
            //Get the tile representation
            Tile::tile curr_tile = this->tile_map[y * this->height + x].get_data();

            //Set the appropriate sprite_sheet area to draw
            sf::IntRect mask_rect = sf::IntRect(((int)curr_tile) * 32, 0, 32, 32);
            to_draw.setTextureRect(mask_rect);

            //Calculate the destination coords for the tile
            to_draw.setPosition((float)x * 32, (float)y * 32);

            //Draw the current tile to active_windows buffer
            active_window->draw(&to_draw);
        }

    }
    
}

Map::Map(std::string map_path, std::string sheet_path) {
    this->map_path = map_path;
    this->sheet_path = sheet_path;
    std::fstream mapfile;

    //Load the sprite sheet for this map.
    if (!this->map_sheet.loadFromFile(this->sheet_path))
    {
        // error...
    }

    //Load map bin data
    std::string delim = ",";
    mapfile.open(this->map_path, std::ios::in);

    unsigned int x = 0;
    unsigned int y = 0;

    if (mapfile.is_open()) {
        std::string new_row;
        std::string tile;

        //Read in height and width data and then create the tile map storage
        std::getline(mapfile, new_row);
        this->width = int(new_row[0] - '0');
        this->height = int(new_row[2] - '0');
        this->tile_map = new Tile[this->width * this->height];

        while (std::getline(mapfile, new_row)) {
            std::stringstream tile_row_stream(new_row);
            //Read in each character for each row
            while (std::getline(tile_row_stream, tile, ',')) {
                Tile* new_tile = new Tile(x, y, (Tile::tile)std::stoi(tile));
                this->add_tile(new_tile);
                x++;
            }
            x = 0;
            y++;
        }
        mapfile.close();
    }
        return;
    }
