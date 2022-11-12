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

Coordinates Coordinates::operator+ (Coordinates const& obj) {
    Coordinates res(0, 0);
    res.set_x(this->get_x() + obj.x);
    res.set_y(this->get_y() + obj.y);
    return res; 

}

void Coordinates::set_y(unsigned int new_y) 
{
    
        this->y = new_y;
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
