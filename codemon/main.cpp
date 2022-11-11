#include <SFML/Graphics.hpp>
<<<<<<< HEAD
#include <string>
#include "data_structures.h"
=======

#include "character.h"

#include <list>
#include <string>

//Class for system selements, should be inherited by every like menus, windows, non game stuff
//Will make useful later
class Sys_element
{

};
>>>>>>> 058ad7da46f5823deab6ba62e1972d7ba5c9fa8e


class Window: private Sys_element
{
private:
    int px_height, px_width;                            //size of the window  in pixels
    sf::RenderWindow *win_obj;                          //Text displayed on the screen bar. 
    std::string display_text;                           //Text displayed on the screen bar. 

public:
    Window(int width, int height, std::string text) {
        this->px_height = height;
        this->px_width = width;
        this->display_text = text;

        //Create Window for the game to take place in; then store  it as a pointer. 
        this->win_obj = new sf::RenderWindow(sf::VideoMode(width, height), this->display_text);
    }

    //Returns openess of windows
    bool is_open() {
        return this->win_obj->isOpen();
    }

    bool change_width(unsigned int width_delta) {
        this->px_width += width_delta;
    }

    bool change_height(unsigned int height_delta) {
        this->px_height += height_delta;
    }

    sf::RenderWindow* get_window() {
        return this->win_obj;
    }
    void close() {
        this->win_obj->close();
    }

    void clear() {
        this->win_obj->clear(sf::Color::Black);
    }

    void draw(character *ch_1) {
        sf::Sprite* sprite = ch_1->get_current_sprite();
        this->win_obj->draw(*sprite);
    }

    bool get_event(sf::Event *event) {
        return this->win_obj->pollEvent(*event);
    }

    void display() {
        this->win_obj->display();
    }

};


int main()
{

    //Main Screen decleration.  
    Window scr(32*32, 32 * 32, "Codemon!");

    //Just keep track of all the windows created - maybe make this into a window manager
    std::list<Window> windows_list;
    windows_list.push_front(scr);

    character player;
    player.load_sprite_sheet();

    while (scr.get_window()->isOpen())
    {
        sf::Event event;
        while (scr.get_event(&event))
        {
            //If the player has closed the game
            switch (event.type) {
            case sf::Event::Closed:
                scr.close();
                break;
                //If a key was pressed
            case sf::Event::KeyPressed:

                //Up was pressed
                if (event.key.code == sf::Keyboard::W) {
                    player.move_y(-32);
                    player.update_sprite_pos();
                }
                //Down was pressed
                else if (event.key.code == sf::Keyboard::S) {
                    player.move_y(32);
                    player.update_sprite_pos();
                }
                //Left was pressed
                else if (event.key.code == sf::Keyboard::A) {
                    player.move_x(-32);
                    player.update_sprite_pos();
                }
                //Right was pressed
                else if (event.key.code == sf::Keyboard::D) {
                    player.move_x(32);
                    player.update_sprite_pos();
                }   
                break;
            }
        }

        scr.clear();
        //draw the sprite to the window
        scr.draw(&player);

        //Update the window to draw stuff
        scr.display();
    }

    return 0;
}