#pragma once
#include "character.h"
#include "direction.h"
#include "Coordinates.h"

class Character
{
private:
	Coordinates pos;
	sf::Texture sprite_sheet;
	sf::Sprite current_sprite;
	sf::Texture* get_sprite_sheet();
	unsigned char walk_anim_index;
	DIR facing;
	
public:
	Character();
	Character(int x, int y);
	int get_x();
	int get_y();
	void set_x(int new_x);
	void set_y(int new_y);
	sf::Sprite* get_current_sprite();
	bool load_sprite_sheet();

	void update_sprite_pos();
	void set_facing(DIR dir);
	void move(DIR move_dir);
	void move_x(int new_x);
	void move_y(int new_y);


	//Returns the characters coords if it moved in a direction
	Coordinates move_cord(DIR move_dir);
	Coordinates get_pos();
};

