
#include "Game.h"

#include <cstdlib>
#include <ctime>
#include <vector>
#include <Windows.h>

#include <iostream>
using namespace std;

Game *game = nullptr;   //assign game pointer

int difficulty = 1;


int main(int argc, char *argv[])
{
	try {
		srand(time(NULL));

		game = new Game();  //start the game, acting as observer

		game->startGame();
	

		std::cin >> difficulty; //choose difficulty

		if (cin.fail())  //If invalid input is received
		{


			std::cout << "Invalid difficulty specified, defaulting to Normal." << std::endl;
			difficulty = 2;
		}

		game->setDifficulty(difficulty);  //assign difficulty

		game->createPlayer();
		game->createEnemy();  //init game methods

		std::vector<int> dungeon = game->createDungeon();

		while (game->running()) {  //the game loop
			
			game->runningGame(dungeon);  //loops until game end
		}
		return EXIT_SUCCESS;
	}
	catch (std::string e) {
		cout << "An unexpected error occurred. Closing game..." << endl;
		return EXIT_FAILURE;  //If something goes wrong
	}
	



	return 0;
}