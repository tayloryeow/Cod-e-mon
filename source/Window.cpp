#include "window.h"
#include <string>

#include "SFML/Graphics.hpp"

Window::Window(int width, int height, std::string text) {
    this->px_height = height;
    this->px_width = width;
    this->display_text = text;

    //Create Window for the game to take place in; then store  it as a pointer. 
    this->win_obj = new sf::RenderWindow(sf::VideoMode(width, height), this->display_text);
}

//Returns openess of windows

bool Window::is_open() {
    return this->win_obj->isOpen();
}

bool Window::change_width(unsigned int width_delta) {
    this->px_width += width_delta;
    return true;
}

bool Window::change_height(unsigned int height_delta) {
    this->px_height += height_delta;
    return true;
}

sf::RenderWindow* Window::get_window() {
    return this->win_obj;
}

void Window::close() {
    this->win_obj->close();
}

void Window::clear() {
    this->win_obj->clear(sf::Color::Black);
}

 void Window::draw(Character* ch_1) {
    sf::Sprite* sprite = ch_1->get_current_sprite();
    this->win_obj->draw(*sprite);
}

 void Window::draw(sf::Sprite *sprite) {
     this->win_obj->draw(*sprite);
 }

 bool Window::get_event(sf::Event* event) {
    return this->win_obj->pollEvent(*event);
}

 void Window::display() {
    this->win_obj->display();
}