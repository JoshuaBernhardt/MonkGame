#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Combat.h"
#include "RoomGenerator.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

Player *player = nullptr;
Enemy *enemy = nullptr;
Combat *battle = nullptr;
RoomGenerator *roomgenerator = nullptr;

bool canMove = true;

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

std::string Game::createPlayer()
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

	player->pos = 0;

	std::string n = player->getName();

	updateLog(name);
	updateLog(desc);

	return n;

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

int Game::currentRoom(int pos, std::vector<int> dungeon)
{
	
	int room = dungeon.at(pos);

	switch (room) {
	case 0:
		std::cout << "Current room is prayer room." << std::endl;
		player->canPray = true;
		return room;
		break;
	case 1:
		std::cout << "Current room is monster room." << std::endl;
		player->canPray = false;
		canMove = false;
		
		return room;
		break;
	case 2:
		std::cout << "Current room is treasure room." << std::endl;
		player->canPray = false;
		return room;
		break;
	}

	player->canPray = false;

	return room;
	
}

void Game::end()
{
	cout << string(100, '\n');
	cout << "Congratulations, you have found the treasure room! Game Over" << endl;
	delete player;
	delete enemy;
	delete roomgenerator;
	delete battle;
}

void Game::runningGame(std::vector<int> dungeon)
{
	
	int pos = player->currentPos();


	int room = Game::currentRoom(pos, dungeon);

	std::cout << "Move Left: 0,  Move Right:  1, Pray: 2,  Attack:  3,   Defend: 4" << std::endl;

	int action;
	std::cin >> action;

	switch (action) {
	case 0: case 1:

		if (canMove == true) {
			pos = player->move(pos, action);
			break;
		}
		
		cout << "You cannot leave this room yet!" << endl;
		break;

	case 2:
		player->pray();
		player->canPray = false;
		break;

	case 3:
		if (room == 1) {

			if (enemy->health <= 0) {
				canMove = true;
				cout << "You have slain the monster." << endl;
			}

			int dmg = player->attack();
			int attack = battle->getPlayerAttack(player->getName(), dmg);
			cout << player->getName() << "'s health is at " << player->health << endl;
		}
		break;
	case 4:
		if (room == 1) {
			
			


		}
		break;

	}

	if (room == 2) {
		Game::end();
	}

	
	player->pos = pos;

}



