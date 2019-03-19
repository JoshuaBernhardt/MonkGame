#include "Player.h"
#include <iostream>

using namespace std;


class player
{


private:
	std::string name;
	std::string description;
	int health = 15;
};

Player::Player()
{

}

Player::~Player()
{}

void Player::pray()
{
	if (canPray == false) {
		std::cout << "You cannot pray outside of a prayer room!" << std::endl;
		return;
	}

	health += 3;
	std::cout << "You pray and regain some health." << std::endl;
	std::cout << health << std::endl;

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



int Player::currentPos()
{
	return 0;
}


