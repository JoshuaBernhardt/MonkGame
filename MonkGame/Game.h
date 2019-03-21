#ifndef Game_h
#define Game_h

#include <vector>
#include <iostream>
using namespace std;

class Game {

public:
	Game();
	~Game();

	void eventHandler();

	void update();

	void setDifficulty(int diff);

	int getDifficulty();

	void updateLog(std::string text);

	std::string createPlayer();

	void createEnemy();

	void startGame();

	std::vector<int> createDungeon();

	int currentRoom(int pos, std::vector<int> dungeon);

	void runningGame(std::vector<int> dungeon);

	void end();





	bool running() { return isRunning; }

private:
	int count=0;
	bool isRunning;
	int difficulty;


};

#endif /*Game_h*/
