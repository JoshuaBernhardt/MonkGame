#include "RoomGenerator.h"
#include "Room.h"
#include <iostream>
#include <vector>

RoomGenerator::RoomGenerator()
{}

RoomGenerator::~RoomGenerator()
{}

std::vector<int> RoomGenerator::generateDungeon()
{
	std::vector<int> dungeon { 0,1,0,1,1,2 };
	
	return dungeon;
	
}



int RoomGenerator::randomRoom()
{
	int selector = rand() % 7;

	switch (selector) {
	case 0: case 1:
		return 0;
		break;
	case 2: case 3: case 4:
		return 1;
		break;
	case 5: case 6: case 7:
		return 2;
		break;
	}

	return 0;

}



