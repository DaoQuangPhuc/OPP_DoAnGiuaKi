#include "Player.h"
#pragma once
class Ball
{
private:
	int posH, posW;

public:
	Ball();
	Ball(int postionH, int postionW);
	int getPosHeight();
	int getPosWidth();
	void setPosition(int positionH, int positionW);
	int autoMove(int& direction, Player player1, Player player2);
};

