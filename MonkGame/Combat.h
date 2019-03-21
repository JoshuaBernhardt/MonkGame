#pragma once
#ifndef Combat_h
#define Combat_h
#include <iostream>
#include <string>

class Combat {


public:
	bool turn;

	int getPlayerAttack(std::string name, int dmg);

	int getEnemyAttack(int dmg);


	int dmg;

};


#endif // !Combat_h

