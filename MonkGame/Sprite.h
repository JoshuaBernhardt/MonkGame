#pragma once
#ifndef Sprite_h
#define Sprite_h
#include <string>

class Sprite {

public:
	Sprite();
	~Sprite();

	int attack();

	int health;

	int takeDamage(int health, int dmg);



protected:

	
	

};

#endif