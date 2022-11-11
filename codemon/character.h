#pragma once
enum DIR { N = 3, E = 2, S = 0, W = 1};


class Character
{
private:
	int x;
	int y;
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
	void move_x(int new_x);
	void move_y(int new_y);
	void update_sprite_pos();
	void set_facing(DIR dir);
};

