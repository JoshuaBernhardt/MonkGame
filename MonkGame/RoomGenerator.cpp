#include "RoomGenerator.h"
#include "Room.h"
#include <iostream>
#include <vector>

using namespace std;

RoomGenerator::RoomGenerator()
{}

RoomGenerator::~RoomGenerator()
{}

std::vector<int> RoomGenerator::generateDungeon()
{
	//generates 10 random rooms
	//can be expanded

	std::vector<int> dungeon;

	for (int i = 0; i < 10; i++) {  //go through vector
		dungeon.push_back(randomRoom());
	}
	
	dungeon.push_back(2); //adds treasure room at the end

	return dungeon;
	
}



int RoomGenerator::randomRoom()
{
	//randomly determine a room to add to the dungeon


	int selector = rand() % 6;


	switch (selector) {
	case 0: case 1:
		return 0;
		break;
	case 2: case 3: case 4:
		return 1;
		break;
	case 5: case 6:

		return 0;
		break;
	}

	

	return 0;

}



