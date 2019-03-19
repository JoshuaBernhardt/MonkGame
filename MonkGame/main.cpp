
#include "Game.h"

#include <iostream>
using namespace std;

Game *game = nullptr;

int difficulty = 1;

int main(int argc, char *argv[])
{

	game = new Game();

	game->startGame();

	std::cin >> difficulty; //choose difficulty
	game->setDifficulty(difficulty);  //assign difficulty
	
	game->createPlayer();
	game->createDungeon();


	while (game->running()) {  //the game loop
		
	}



	return 0;
}