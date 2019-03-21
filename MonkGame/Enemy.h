#pragma once
#ifndef Enemy_h
#define Enemy_h
#include "Sprite.h"

class Enemy: public Sprite {


public:
	Enemy();
	~Enemy();

	int attack(int diff);

	int health;


private:

	enum type {Goblin};


};

#endif // !Enemy_h
