#include "Coordinates.h"

unsigned int Coordinates::get_x()
{
    return this->x;
}

unsigned int Coordinates::get_y()
{
    return this->y;
}



void Coordinates::set_x(unsigned int new_x)
{
    this->x = new_x;
}

void Coordinates::set_y(unsigned int new_y)
{

    this->y = new_y;
}

//Tests wether this coordinate is strictly within a square descirbed 
//by the given coordinate
//This in That
bool Coordinates::in(Coordinates is_this_within) {

    bool within_x = this->get_x() < is_this_within.get_x() && this->get_x() >= 0;
    bool within_y = this->get_y() < is_this_within.get_y() && this->get_y() >= 0;

    return within_x && within_y;

}

Coordinates Coordinates::operator+ (Coordinates const& obj) {
    Coordinates res(0, 0);
    res.set_x(this->get_x() + obj.x);
    res.set_y(this->get_y() + obj.y);
    return res; 

}

void Coordinates::operator= (Coordinates * obj) {
    this->x = obj->x;
    this->y = obj->y;
}

unsigned int Coordinates::area() {
    return this->get_x() * this->get_y();
}




Coordinates::Coordinates() {
    this->x = 0;
    this->y = 0;
}

Coordinates::Coordinates(unsigned int x, unsigned int y)
{
    this->y = y;
    this->x = x;
}
