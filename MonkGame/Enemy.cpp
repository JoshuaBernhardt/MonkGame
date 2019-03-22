#include "Enemy.h"

#include <iostream>

class enemy
{
public:
	int *health;

};


Enemy::Enemy() {

	this->health = 8;
}

Enemy::~Enemy()
{
}

int Enemy::attack(int diff) {

//varying damage depending on difficulty

	std::cout << "The enemy attacks you!" << std::endl;

	int chance = rand() % 100;   //50% chance of failure

	if (chance > 50) {
		switch (diff) {
		case 0:
			std::cout << "Dealing 1 damage!" << std::endl;
			return 1;
			break;
		case 1:
			std::cout << "Dealing 2 damage!" << std::endl;
			return 2;
			break;
		case 2:
			std::cout << "Dealing 3 damage!" << std::endl;
			return 3;
			break;
		case 3:
			std::cout << "Dealing 4 damage!" << std::endl;
			return 4;
			break;

		}

		
		return 0;
	}

	std::cout << "They miss! Dealing 0 damage!" << std::endl;

	return 0;

	




	return 1;

}
