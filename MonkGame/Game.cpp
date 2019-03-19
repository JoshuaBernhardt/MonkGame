#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "RoomGenerator.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

Player *player = nullptr;
Enemy *enemy = nullptr;
RoomGenerator *roomgenerator = nullptr;

Game::Game()
{}
Game::~Game()
{}


void Game::eventHandler()
{
	
}

void Game::update()
{
}

void Game::updateLog(std::string text)
{

	
	ofstream log;
	log.open("log.txt", std::ios_base::app);
	log << text << "\n";

	if (isRunning == false) {
		log.close();
	}

	
}



int Game::getDifficulty() {
	return difficulty;
}

void Game::setDifficulty(int diff)
{
	difficulty = diff;

	switch(difficulty) {
	case 0:
		std::cout << "Difficulty set to super easy." << std::endl;
		break;
	case 1:
		std::cout << "Difficulty set to easy." << std::endl;
		break;
	case 2:
		std::cout << "Difficulty set to normal." << std::endl;
		break;
	case 3:
		std::cout << "Difficulty set to hard." << std::endl;
		break;
	default:
		std::cout << "Difficulty set to normal." << std::endl;
		break;
	}

}

void Game::createPlayer()
{
	player = new Player;

	std::string name;
	std::string desc;

	std::cout << "Please enter a name for your character." << std::endl;

	cin.ignore();

	getline(cin, name);

	std::cout << "Please enter a description for your character." << std::endl;

	getline(cin, desc);

	player->setName(name);
	player->setDesc(desc);

	std::string n = player->getName();

	updateLog(name);
	updateLog(desc);

}

void Game::createEnemy()
{
	enemy = new Enemy;
}

void Game::startGame()
{

	isRunning = true;

	std::cout << "Welcome to Monk!" << std::endl;
	std::cout << "Select your chosen difficulty." << std::endl;
	std::cout << "0: Super Easy" << std::endl;
	std::cout << "1: Easy" << std::endl;
	std::cout << "2: Normal" << std::endl;
	std::cout << "3: Hard" << std::endl;

	

	

}



std::vector<int> Game::createDungeon()
{
	roomgenerator = new RoomGenerator;

	std::vector<int> dungeon = roomgenerator->generateDungeon();

	return dungeon;
}

int Game::currentRoom(int pos)
{
	
	std::vector<int> dungeon = createDungeon();

	int room = dungeon.at(pos);


	switch (room) {
	case 0:
		std::cout << "Current room is prayer room." << std::endl;
	case 1:
		std::cout << "Current room is monster room." << std::endl;
	case 2:
		std::cout << "Current room is treasure room." << std::endl;
	}

	return room;
	
}


