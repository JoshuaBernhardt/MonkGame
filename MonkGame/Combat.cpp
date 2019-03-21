#include "Combat.h"
#include <iostream>

using namespace std;


int Combat::getPlayerAttack(std::string name, int dmg)
{

	if (dmg == 0) {
		return dmg;
	}

	std::cout << name << " attacks, dealing " << dmg << " damage!" << std::endl;

	return dmg;
}

int Combat::getEnemyAttack(int dmg)
{
	return dmg;
}

