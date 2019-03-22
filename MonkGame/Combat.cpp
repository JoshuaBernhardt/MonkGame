#include "Combat.h"
#include <iostream>

using namespace std;


int Combat::getPlayerAttack(std::string name, int dmg)
{

	//combat system, provides updates for player

	if (dmg == 0) {
		std::cout << name << " attacks but misses!\n" << std::endl;
		return dmg;
	}

	if (dmg == 6) {
		std::cout << name << " lands a critical attack! Dealing " << dmg << " damage!\n" << std::endl;
		return dmg;
	}

	std::cout << name << " attacks, dealing " << dmg << " damage!\n" << std::endl;

	return dmg;
}

int Combat::getEnemyAttack(int dmg)
{
	return dmg;
}

