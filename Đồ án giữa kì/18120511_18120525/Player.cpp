#include "Player.h"

Player::Player()
{
}

Player::Player(int positonHeight, int positionWidth) {
	posW = positionWidth;
	posH = positonHeight;
}

int Player::getPositionW() {
	return posW;
}

int Player::getPositionH() {
	return posH;
}

void Player::setPositionW(int value) {
	posW = value;
}

void Player::moveLeft() {
	posW--;
	if ((posW - PAD_LENGTH) <= 0) {
		posW++;
	}
}

void Player::moveRight() {
	posW++;
	if ((posW + PAD_LENGTH) >= MAX_WIDTH - 1) {
		posW--;
	}
}