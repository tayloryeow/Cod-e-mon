#pragma once

/*
Private coordinates tuple class.
Just a wrapped for x and y variables. I chose to go this direction
and roll my own just for less dependancies and more flexibility. 
Additionally rolled my own as an exercise.

Operates on getters setters, etc.. can be created with default or over ridden values.
Vector addition also is supported

*/
class Coordinates
{
private:
	unsigned int x;
	unsigned int y;
public:
	unsigned int get_x();
	unsigned int get_y();
	void set_x(unsigned int new_x);
	void set_y(unsigned int new_y);
	Coordinates();
	Coordinates(unsigned int x, unsigned int y);
	Coordinates operator+ (Coordinates const& obj);
};

