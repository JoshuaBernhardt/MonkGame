#include "Sprite.h"
#include <iostream>

Sprite::Sprite()
{}

Sprite::~Sprite()
{}


int Sprite::attack()
{
	int chance = rand() % 100; //attack with 50% chance of success

	if (chance > 90) {
		return 6;      //rare critical attack 10% chance
	}


	if (chance > 50) {
		return 3;
	}

	
	return 0;

}

int Sprite::takeDamage(int health, int dmg)
{
	if ((this->health - dmg) <= 0) {
		return 0; 
	}


	this->health -= dmg;

	return this->health;
}
