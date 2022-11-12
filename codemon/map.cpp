#include "map.h"
#include "Tile.h"
#include "Window.h"
#include <string>
#include <sstream>
#include <iostream>
#include <cassert>

unsigned int Map::get_height() {
    return this->get_size().get_x();
}

unsigned int Map::get_width() {
    return this->get_size().get_y();
}

void Map::add_tile(Tile *new_tile)
{
    this->tile_map[new_tile->get_x() + new_tile->get_y() *this->get_width()] = *new_tile;
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
    for (unsigned int y = 0; y < this->get_height(); y++){             //Each row
        for (unsigned int x = 0; x < this->get_width(); x++) {         //Each column in each row
            //Get the tile representation
            Tile::tile curr_tile = this->tile_map[y * this->get_height() + x].get_data();

            //Set the appropriate sprite_sheet area to draw
            //#1 - Current tile which represents its location in the tilelist * index size
            //#2 - What row its on
            //#3 - Tile width
            //#4 - Tile height
            sf::IntRect mask_rect = 
                sf::IntRect(
                    ((int) curr_tile) * this->tile_size, 0, 
                    this->tile_size, this->tile_size
                );
            to_draw.setTextureRect(mask_rect);

            //Calculate the destination coords for the tile
            to_draw.setPosition((float)x * this->tile_size, (float)y * this->tile_size);

            //Draw the current tile to active_windows buffer
            active_window->draw(&to_draw);
        }

    }
    
}


bool Map::in_bounds(Coordinates proposed_coord) {
    return proposed_coord.in(this->get_size());
}


unsigned int Map::get_tile_size() {
    return this->tile_size;
}


Map::Map(std::string map_path, std::string sheet_path) {
    this->map_path = map_path;
    this->sheet_path = sheet_path;
    std::fstream mapfile;

    //Create the immutables
    tile_size = 32;
    this->size = new Coordinates();

    //Load the sprite sheet for this map.
    if (!this->map_sheet.loadFromFile(this->sheet_path))
    {
        // error...
    }

    //Load map bin data
    std::string delim = ",";
    mapfile.open(this->map_path, std::ios::in);


    if (mapfile.is_open()) {
        std::string new_row;
        std::string tile;

        //Read in height and width data and then create the tile map storage
        std::getline(mapfile, new_row);
        unsigned int width = int(new_row[0] - '0');
        unsigned int height = int(new_row[2] - '0');

        this->size = new Coordinates(width, height);

        //Decalre the memory for the tile area map
        this->tile_map = new Tile[this->get_size().area()];

        unsigned int x = 0;
        unsigned int y = 0;
        while (std::getline(mapfile, new_row)) {
            std::stringstream tile_row_stream(new_row);
            //Read in each character for each row
            while (std::getline(tile_row_stream, tile, ',')) {
                //Create a tile with pos info and its tile enum id
                Tile* new_tile = new Tile(x, y, (Tile::tile) std::stoi(tile));
                //Add the tile to the matrix.
                this->add_tile(new_tile);
                x++;
            }
            x = 0;
            y++;
        }
        mapfile.close();
    }
}

Coordinates Map::get_size() {
    return this->size;
}