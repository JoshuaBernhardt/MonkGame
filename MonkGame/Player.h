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

	void nextRoom();

	void prevRoom();







private:
	std::string name ="Default";
	std::string description = "Default";
	int health;
	bool canPray = false;


};

#endif // !Player_h