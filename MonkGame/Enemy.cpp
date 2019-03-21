#include "Enemy.h"



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

	switch (diff) {
	case 0:
		return 1;
		break;
	case 1:
		return 2;
		break;
	case 2:
		return 3;
		break;
	case 3:
		return 4;
		break;

	}




	return 1;

}
