#include "SFML/Graphics.hpp"
#include "character.h"


character::character() {
	this->x = 0;
	this->y = 0;
	sf::Texture sprite_sheet;
	sf::Sprite current_sprite;
	this->walk_anim_index = 0;
	this->facing = N;
}

character::character(int x, int y) {
	this->x = x;
	this->y = y;
	this->walk_anim_index = 0;
	sf::Texture sprite_sheet;
	sf::Sprite current_sprite;
	this->facing = N;
}

int character::get_x()
{
	return this->x;
}

int character::get_y()
{
	return this->y;
}

void character::set_x(int new_x)
{
	this->x = new_x;
}

void character::set_y(int new_y)
{
	this->x = new_y;
}

void character::move_x(int new_x)
{

	if (this->x - (new_x + this->x) >= 0) {
		this->set_facing(W);
	}
	else {
		this->set_facing(E);
	}
	this->x += new_x;

}

void character::move_y(int new_y)
{

	if (this->y - (new_y + this->y)>= 0) {
		this->set_facing(N);
	}
	else {
		this->set_facing(S);
	}
	this->y += new_y;
}

sf::Sprite* character::get_current_sprite()
{
	//Update sprite
	return &this->current_sprite;
}

sf::Texture* character::get_sprite_sheet() {
	return &this->sprite_sheet;
}


bool character::load_sprite_sheet()
{
	if (!this->sprite_sheet.loadFromFile("assets/Red_player.png")) {
		return false;
	}
	this->current_sprite.setTexture(*this->get_sprite_sheet());
	this->current_sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	return true;
}

void character::update_sprite_pos() {

	sf::IntRect walk_mask = sf::IntRect(walk_anim_index * 32, this->facing * 32, 32, 32);

	this->current_sprite.setPosition((float)this->x, (float)this->y);
	this->current_sprite.setTextureRect(walk_mask);
	this->walk_anim_index = this->walk_anim_index + 1;
	this->walk_anim_index = this->walk_anim_index % 3;
}

void character::set_facing(DIR dir)
{
	this->facing = dir;
}
