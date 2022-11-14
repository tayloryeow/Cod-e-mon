#include "map.h"
#include "Tile.h"
#include "Window.h"
#include <string>
#include <sstream>
#include <iostream>
#include <cassert>

Map::Map(std::string map_path, std::string sheet_path) {

    /*Initialize all state variables*/
    this->set_dimensions(Coordinates(0, 0));
    this->set_start_pos(Coordinates(0, 0));

    this->map_path = map_path;
    this->sheet_path = sheet_path;
    std::fstream mapfile;

    /*
    * Load - the sprite sheet for this map.
    */
    if (!this->map_sheet.loadFromFile(this->sheet_path))
    {
        // error...
    }

    /*
    * Load - the integer map textfile for this map
    */
    std::string delim = ",";
    mapfile.open(this->map_path, std::ios::in);

    unsigned int x = 0;
    unsigned int y = 0;

    //if the map_storage file is successfully open
    if (mapfile.is_open()) {
        std::string new_row;
        std::string tile;

        //Read in height and width data and then create the tile map storage
        std::getline(mapfile, new_row);
        this->set_width(unsigned int(new_row[0] - '0'));
        this->set_height(unsigned int(new_row[2] - '0'));

        //Create the tile storage matrix
        this->tile_map = new Tile[this->get_width() * this->get_height()];

        //Read in each Tile::enum and create a tile obj for it. Store it in the tile_map
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
        //Close the input file after reading.
        mapfile.close();
    }
        return;
}

//Return a texture rendered from get_map();
//This only works because each tilesheet is constructed such that its enum value is its position in the 
//tile sheet row
void Map::render_map(Window* active_window)
{
    //Get the spritesheet read to sample from
    sf::Sprite to_draw(this->map_sheet);
    //Read through tile_map and render each tile
    for (unsigned int y = 0; y < this->get_height(); y++) {             //Each row
        for (unsigned int x = 0; x < this->get_height(); x++) {         //Each column in each row
            //Get the tile representation
            Tile::tile curr_tile = this->tile_map[y * this->get_height() + x].get_data();

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

bool Map::in_bounds(Coordinates proposed_coord) {
    return true;
}

/*
Getters and Setters
*/

void Map::set_dimensions(Coordinates dim) {
    this->dimensions = dim;
}

Coordinates* Map::get_dimensions() {
    return &this->dimensions;
}

void Map::set_width(unsigned int width) {
    this->get_dimensions()->set_x(width);
}

unsigned int Map::get_height() {
    return this->get_dimensions()->get_y();
}

void Map::set_height(unsigned int height) {
    this->get_dimensions()->set_y(height);
}

unsigned int Map::get_width() {
    return this->get_dimensions()->get_x();
}

void Map::set_start_pos(Coordinates start) {
    this->start_pos = start;
}

Tile* Map::get_map()
{
    return this->tile_map;
}

void Map::add_tile(Tile* new_tile)
{
    this->tile_map[new_tile->get_x() + new_tile->get_y() * this->get_width()] = *new_tile;
}