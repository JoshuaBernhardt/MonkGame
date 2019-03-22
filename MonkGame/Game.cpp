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
	//adds actions to file log.txt
	
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
	difficulty = diff;   //handling of difficulty

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
	player = new Player;  //init the player

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

	updateLog(name);  //add to log
	updateLog(desc);

	return n;

}

void Game::createEnemy()
{
	enemy = new Enemy;  //create enemy object
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

	//start the game

}



std::vector<int> Game::createDungeon()
{
	roomgenerator = new RoomGenerator;   //generate the dungeon using algorithm

	std::vector<int> dungeon = roomgenerator->generateDungeon();

	return dungeon;
}

int Game::currentRoom(std::vector<int> dungeon, int pos)
{
	int room = dungeon.at(pos);  //determine position of player in dungeon and thus what room they are in

	switch (room) {
	case 0:
		std::cout << "Current room is prayer room.\n" << std::endl;
		updateLog("Current Room is prayer room.");
		player->canPray = true;
		return room;
		break;
	case 1:
		std::cout << "Current room is monster room.\n" << std::endl;
		updateLog("Current Room is monster room.");
		player->canPray = false;    //prevents movement and praying
		canMove = false;
		cout << "Monster health is: " << enemy->health << endl;
		
		return room;
		break;
	case 2:
		std::cout << "Current room is treasure room.\n" << std::endl;
		updateLog("Current Room is treasure room.");
		player->canPray = false;
		return room;
		break;
	}

	player->canPray = false;

	return room;
	
}

void Game::end(int result)
{  //end the game

	switch (result) {
	case 0:
		cout << string(100, '\n');
		cout << "Congratulations, you have found the treasure room! Game Over" << endl;
		cout << "Enter any action to collect!" << endl;
		updateLog("Congratulations, you have found the treasure room! Game Over");
		updateLog("Enter any action to collect!");  //if end is positive
		
		break;
	case 1:
		cout << string(100, '\n');   //if player dies
		cout << "You died, game over" << endl;
		updateLog("You died, game over");
		break;
	}

	delete player;  //cleanup
	delete enemy;
	delete roomgenerator;
	delete battle;
	isRunning = false;
	}
	

void Game::runningGame(std::vector<int> dungeon)
{

	if (player->health <= 0) {
		Game::end(1);
		isRunning = false;
	}
	
	int pos = player->currentPos();  //the main game loop

	std::cout << "Move Left: 0,  Move Right:  1, Pray: 2,  Attack:  3,   Defend: 4\n" << std::endl;

	int room = Game::currentRoom(dungeon, pos); //get current room



	
	cout << player->getName() << "'s health is at " << player->health << endl;
	updateLog("players health is at " + player->health);
	

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

	case 3:  //attack combat
		if (room == 1) {
			cout << player->getName() << "'s health is at " << player->health << endl;
			cout << "Monster health is: " << enemy->health << endl;
			updateLog("Monster health is: " + enemy->health);

			if (enemy->health <= 0) {
				canMove = true;
				cout << "You have slain the monster.\n" << endl;
				cout << "You move to the next room...\n" << endl;
				pos = player->move(pos, 1);
				if (room == 2) {
					Game::end(0);
				}
				enemy->health = 8;
				break;
			}

			int dmg = player->attack();
			int attack = battle->getPlayerAttack(player->getName(), dmg);

			if (((enemy->health) - attack) <= 0) {   //prevents health going out of range
				canMove = true;
				cout << "You have slain the monster.\n" << endl;
				cout << "You move to the next room...\n" << endl;
				pos = player->move(pos, 1);
				enemy->health = 8;
				break;
			}
			enemy->health = enemy->health - attack;  //get attack
			int enemattack = enemy->attack(difficulty);


			if ((player->health-enemattack) <=0) {
				player->health = 1;
				Game::end(1);
				isRunning = false;
			}
			player->health = player->health - enemattack;
			
		}
		break;
	case 4:
		if (room == 1) {
			
			cout << "You take a defensive stance and your health increases by 1!" << endl;
			updateLog("You take a defensive stance and your health increases by 1!");
			player->health += 1;

			cout << player->getName() << "'s health is at " << player->health << endl;
			cout << "Monster health is: " << enemy->health << endl;
			updateLog("Monster health is: " + enemy->health);

			if (enemy->health <= 0) { //kill monster
				canMove = true;
				cout << "You have slain the monster.\n" << endl;
				cout << "You move to the next room...\n" << endl;
				pos = player->move(pos, 1);
				enemy->health = 8;  //reset object for next battle
				break;
			}

			int enemattack = enemy->attack(difficulty);


			if ((player->health - enemattack) <= 0) {
				player->health = 1;
				Game::end(1);
				isRunning = false;
			}
			player->health = player->health - enemattack;


		}
		break;

	case 99:
		Game::end(0);
		isRunning = false;  //End the game before reaching the end for dev purposes

	}

	if (room == 2) {
		Game::end(0);  //if treasure room reached
	}

	
	player->pos = pos; //update position

}



