#include "Constant.h"
#pragma once
class Player
{
private:
	int posH, posW;

public:
	Player();
	Player(int positonHeight, int positionWidth);
	int getPositionW();
	int getPositionH();
	void setPositionW(int value);
	void moveLeft();
	void moveRight();
};