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
}

Character::Character(int x, int y) {
	
	this->pos = Coordinates(x, y);
	this->walk_anim_index = 0;
	sf::Texture sprite_sheet;
	sf::Sprite current_sprite;
	this->facing = DIR::NONE;
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

//Move this character by and ammount on the X axis.
//-Set facing direction for the character
//-Move the character
//-No error, bounds or collision checks
void Character::move_x(int new_x)
{
	//Determine which direction the proposed move (new_x) is in.
	if (new_x >= 0) {
		this->set_facing(DIR::E); //Face East
	}
	else {
		this->set_facing(DIR::W); //Face West
	}
	//Add the diff to this character's position
	this->set_x(this->get_x() + new_x);
}

//Move this character by and ammount on the Y axis.
//-Set facing direction for the character
//-Move the character
//-No error, bounds or collision checks
void Character::move_y(int new_y)
{
	if (new_y >= 0) {
		this->set_facing(DIR::S);
	}
	else {
		this->set_facing(DIR::N);
	}
	//Add the diff to this character's position
	this->set_y(this->get_y() + new_y);
}

//Return this character's position
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
		delta = delta + Coordinates(1, 0);
		break;
	case DIR::S:
		delta = delta + Coordinates(-1, 0);
		break;
	case DIR::E:
		delta = delta + Coordinates(0, 1);
		break;
	case DIR::W:
		delta = delta + Coordinates(0, -1);
		break;
	}

	return this->get_pos() + delta;

}

void Character::move(DIR new_dir)
{
	//Make sure its a valid move direction
	assert(new_dir != DIR::NONE);
	this->facing = new_dir;
	switch (new_dir) {
	case DIR::N:
		move_y(-32);
		break;
	case DIR::S:
		move_y(32);
		break;
	case DIR::E:
		move_x(32);
		break;
	case DIR::W:
		move_x(-32);
		break;
	}
}


void Character::update_sprite_pos() {

	sf::IntRect walk_mask = sf::IntRect(walk_anim_index * 32, this->facing * 32, 32, 32);

	this->current_sprite.setPosition((float)this->get_x(), (float)this->get_y());
	this->current_sprite.setTextureRect(walk_mask);
	this->walk_anim_index = this->walk_anim_index + 1;
	this->walk_anim_index = this->walk_anim_index % 3;
}

void Character::set_facing(DIR dir)
{
	this->facing = dir;
}