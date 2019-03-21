#pragma once
#ifndef Player_
#define Player_h
#include <string>

#include "Sprite.h"



class Player: public Sprite {

public:
	Player();
	~Player();

	void pray();

	void setName(std::string n);

	void setDesc(std::string desc);


	std::string getName();

	std::string getDesc();


	void setPos(int p);

	int move(int pos, int input);

	int currentPos();

	int pos = 0;
	bool canPray = false;

	int health;

private:
	std::string name ="Default";
	std::string description = "Default";
	





};

#endif // !Player_h