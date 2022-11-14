#pragma once
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

