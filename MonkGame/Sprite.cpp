#include "Sprite.h"
#include <iostream>

Sprite::Sprite()
{}

Sprite::~Sprite()
{}


int Sprite::attack()
{
	int chance = rand() % 100;

	if (chance > 50) {
		return 3;
	}

	return 0;

}

int Sprite::takeDamage(int health, int dmg)
{
	if ((health - dmg) <= 0) {
		std::cout << "Game Over, you died." << std::endl;
	}


	health -= dmg;

	return health;
}
