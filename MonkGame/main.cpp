
#include "Game.h"

#include <cstdlib>
#include <ctime>
#include <vector>

#include <iostream>
using namespace std;

Game *game = nullptr;

int difficulty = 1;

int main(int argc, char *argv[])
{

	srand(time(NULL));

	game = new Game();

	game->startGame();
	

	

	std::cin >> difficulty; //choose difficulty
	game->setDifficulty(difficulty);  //assign difficulty
	
	game->createPlayer();
	
	
	std::vector<int> dungeon = game->createDungeon();

	while (game->running()) {  //the game loop
		game->runningGame(dungeon);
	}



	return 0;
}