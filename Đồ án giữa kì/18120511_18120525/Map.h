#include "Player.h"
#include "Ball.h"
#include <iostream>

#pragma once

using namespace std;

class Map
{
private:

	int map[MAX_HEIGHT][MAX_WIDTH];

public:
	Map();
	void PrintLogicMap();
	void PrintMap();
	void ResetMap();
	void SetMapObject(Player player1, Player player2, Ball ball);
};

