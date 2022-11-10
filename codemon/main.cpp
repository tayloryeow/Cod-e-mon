#include <SFML/Graphics.hpp>

#include <string>

#include "data_structures.h"

class Sys_element
{

};


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
        sf::RenderWindow window(sf::VideoMode(width, height), this->display_text);
        this->win_obj = &window;
    }

    bool is_open() {
        return (this->win_obj->isOpen());
    }

    bool change_width(unsigned int width_delta) {
        this->px_width += width_delta;
    }

    bool change_height(unsigned int height_delta) {
        this->px_height += height_delta;
    }

};


int main()
{

    //Main Screen decleration.  
    Window scr(200, 200, "Codemon!");

    while (scr.is_open()) {


    }
}
