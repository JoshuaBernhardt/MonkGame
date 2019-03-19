#pragma once
#ifndef RoomGenerator_h
#define RoomGenerator_h
#include <vector>

class RoomGenerator {

public:
	RoomGenerator();
	~RoomGenerator();

	std::vector<int> generateDungeon();

	void returnDungeon();

	int randomRoom();

protected:


private:


};



#endif // !RoomGenerator_h

