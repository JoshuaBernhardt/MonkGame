#include "Player.h"
#include "Game.h"
#include <iostream>

using namespace std;


class player
{
public:
	int *pos = 0;
	bool canPray = false;
	bool canMove = true;
	int *health;


private:
	std::string name;
	std::string description;
	

};

Player::Player()
{
	this->health = 15;
}

Player::~Player()
{}

void Player::pray()
{


	if (canPray == false) {
		std::cout << "You cannot pray outside of a prayer room!" << std::endl;
		return;
	}

	health = 15;
	std::cout << "You pray and refill your health." << std::endl;

}

void Player::setName(std::string n)
{
	name = n;

	std::cout << "Player name set to: " << n << std::endl;

}

void Player::setDesc(std::string desc)
{
	std::cout << "Player description set to: " << desc << std::endl;
}

std::string Player::getName()
{
	return name;
}

std::string Player::getDesc()
{
	return std::string();
}

int Player::move(int pos, int input) {
	
	switch (input) {   //determine position in dungeon
	case 0:
		if (pos > 0) {  //prevents moving out of bounds
			pos -= 1;
			return pos;
			break;
		}

		std::cout << "You can't go back any further!" << std::endl;
		return pos;
		break;

	case 1:

		if (pos < 10) { //Checks if at end
			pos += 1;
			return pos;
			break;
		}

		std::cout << "You can't go any further!" << std::endl;

		return pos;
		break;


		

	}

	return pos;
}

void Player::setPos(int p)
{
	int pos = p;
}


int Player::currentPos()
{
	return this->pos;
}


