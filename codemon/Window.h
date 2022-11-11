#pragma once


#include "SFML/Graphics.hpp"
#include "character.h"

//Class for system selements, should be inherited by every like menus, windows, non game stuff
//Will make useful later
class Sys_element
{

};


class Window : private Sys_element
{
private:
    int px_height, px_width;                            //size of the window  in pixels
    sf::RenderWindow* win_obj;                          //Text displayed on the screen bar. 
    std::string display_text;                           //Text displayed on the screen bar. 

public:
    Window(int width, int height, std::string text);

    //Returns openess of windows
    bool is_open();

    bool change_width(unsigned int width_delta);

    bool change_height(unsigned int height_delta);

    sf::RenderWindow* get_window();
    void close();

    void clear();

    void draw(Character* ch_1);
    void draw(sf::Sprite* sprite);


    bool get_event(sf::Event* event);

    void display();

};