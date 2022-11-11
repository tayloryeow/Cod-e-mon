#include "SFML/Graphics.hpp"
#include "character.h"


Character::Character() {
	this->x = 0;
	this->y = 0;
	sf::Texture sprite_sheet;
	sf::Sprite current_sprite;
	this->walk_anim_index = 0;
	this->facing = N;
}

Character::Character(int x, int y) {
	this->x = x;
	this->y = y;
	this->walk_anim_index = 0;
	sf::Texture sprite_sheet;
	sf::Sprite current_sprite;
	this->facing = N;
}

int Character::get_x()
{
	return this->x;
}

int Character::get_y()
{
	return this->y;
}

void Character::set_x(int new_x)
{
	this->x = new_x;
}

void Character::set_y(int new_y)
{
	this->x = new_y;
}

void Character::move_x(int new_x)
{

	if (this->x - (new_x + this->x) >= 0) {
		this->set_facing(W);
	}
	else {
		this->set_facing(E);
	}
	this->x += new_x;

}

void Character::move_y(int new_y)
{

	if (this->y - (new_y + this->y)>= 0) {
		this->set_facing(N);
	}
	else {
		this->set_facing(S);
	}
	this->y += new_y;
}

sf::Sprite* Character::get_current_sprite()
{
	//Update sprite
	return &this->current_sprite;
}

sf::Texture* Character::get_sprite_sheet() {
	return &this->sprite_sheet;
}


bool Character::load_sprite_sheet()
{
	if (!this->sprite_sheet.loadFromFile("assets/Red_player.png")) {
		return false;
	}
	this->current_sprite.setTexture(*this->get_sprite_sheet());
	this->current_sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	return true;
}

void Character::update_sprite_pos() {

	sf::IntRect walk_mask = sf::IntRect(walk_anim_index * 32, this->facing * 32, 32, 32);

	this->current_sprite.setPosition((float)this->x, (float)this->y);
	this->current_sprite.setTextureRect(walk_mask);
	this->walk_anim_index = this->walk_anim_index + 1;
	this->walk_anim_index = this->walk_anim_index % 3;
}

void Character::set_facing(DIR dir)
{
	this->facing = dir;
}
