#include "SFML/Graphics.hpp"
#include "character.h"
#include "direction.h"
#include "Coordinates.h"
#include "map.h"
#include <cassert>


Character::Character() {
	this->pos = Coordinates(0, 0);
	this->walk_anim_index = 0;
	sf::Texture sprite_sheet;
	sf::Sprite current_sprite;
	this->facing = DIR::NONE;
	stride = 1;
}

Character::Character(int x, int y) {
	
	this->pos = Coordinates(x, y);
	this->walk_anim_index = 0;
	sf::Texture sprite_sheet;
	sf::Sprite current_sprite;
	this->facing = DIR::NONE;
	stride = 1;
}

int Character::get_x()
{
	return this->pos.get_x();
}

int Character::get_y()
{
	return this->pos.get_y();
}

void Character::set_x(int new_x)
{
	this->pos.set_x(new_x);
}

void Character::set_y(int new_y)
{
	this->pos.set_y(new_y);
}


Coordinates Character::get_pos()
{
	return this->pos;
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

Coordinates Character::move_cord(DIR move_dir) {
	assert(move_dir != DIR::NONE);

	Coordinates delta(0,0);

	switch (move_dir) {
	case DIR::N:
		delta = Coordinates(0, -1);
		break;
	case DIR::S:
		delta = Coordinates(0, 1);
		break;
	case DIR::E:
		delta = Coordinates(1, 0);
		break;
	case DIR::W:
		delta = Coordinates(-1, 0);
		break;
	}

	return this->get_pos() + delta;

}

//Move in a direction
void Character::move(DIR new_dir)
{
	//Make sure its a valid move direction
	assert(new_dir != DIR::NONE);
	this->set_facing(new_dir);
	this->pos = this->move_cord(new_dir);
}


void Character::update_sprite_pos() {
	unsigned int sprite_x = walk_anim_index * 32;
	unsigned int sprite_y = this->facing * 32;

	sf::IntRect walk_mask = sf::IntRect(sprite_x, sprite_y, 32, 32);



	this->current_sprite.setPosition((float)this->get_x() * 32, (float)this->get_y() * 32);
	this->current_sprite.setTextureRect(walk_mask);
	this->walk_anim_index = (this->walk_anim_index + 1) % 3;
}

void Character::set_facing(DIR dir)
{
	this->facing = dir;
}
