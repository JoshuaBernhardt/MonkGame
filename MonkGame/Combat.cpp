#include "Combat.h"
#include <iostream>

using namespace std;


int Combat::getPlayerAttack(std::string name, int dmg)
{

	//combat system, provides updates for player

	if (dmg == 0) {
		std::cout << name << " attacks but misses!" << std::endl;
		return dmg;
	}

	std::cout << name << " attacks, dealing " << dmg << " damage!" << std::endl;

	return dmg;
}

int Combat::getEnemyAttack(int dmg)
{
	return dmg;
}

