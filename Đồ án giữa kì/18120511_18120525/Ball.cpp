#include "Ball.h"

Ball::Ball()
{
}

Ball::Ball(int positionH, int positionW) {
	posH = positionH;
	posW = positionW;
}

int Ball::getPosHeight() {
	return posH;
}

int Ball::getPosWidth() {
	return posW;
}

void Ball::setPosition(int positionH, int positionW) {
	posH = positionH;
	posW = positionW;
}

int Ball::autoMove(int& direction, Player player1, Player player2) {
	switch (direction)
	{
	case DIR_LEFT_DOWN:
		posH++;
		posW--;
		if (posW == 0) {
			posH--;
			posW++;
			direction = DIR_RIGHT_DOWN;
			autoMove(direction, player1, player2);
		}
		else if (posH == MAX_HEIGHT - 1) {
			return PLAYER1_WIN;
		}
		else if (posH == player2.getPositionH()) {
			if (posW <= (player2.getPositionW() + PAD_LENGTH) && posW >= (player2.getPositionW() - PAD_LENGTH)) {
				posH--;
				posW++;
				direction = DIR_LEFT_UP;
			}
		}
		break;
	case DIR_LEFT_UP:
		posH--;
		posW--;
		if (posW == 0) {
			posH++;
			posW++;
			direction = DIR_RIGHT_UP;
			autoMove(direction, player1, player2);
		} else if (posH == 0) {
			return PLAYER2_WIN;
		} else if (posH == player1.getPositionH()) {
			if (posW <= (player1.getPositionW() + PAD_LENGTH) && posW >= (player1.getPositionW() - PAD_LENGTH)) {
				posH++;
				posW++;
				direction = DIR_LEFT_DOWN;
			}
		}
		break;
	case DIR_RIGHT_DOWN:
		posH++;
		posW++;
		if (posW == MAX_WIDTH - 1) {
			posH--;
			posW--;
			direction == DIR_LEFT_DOWN;
			autoMove(direction, player1, player2);
		} else if (posH == MAX_HEIGHT - 1) {
			return PLAYER1_WIN;
		}
		else if (posH == player2.getPositionH()) {
			if (posW <= (player2.getPositionW() + PAD_LENGTH) && posW >= (player2.getPositionW() - PAD_LENGTH)) {
				posH--;
				posW++;
				direction = DIR_RIGHT_UP;
			}
		}
		break;
	case DIR_RIGHT_UP:
		posH--;
		posW++;
		if (posW == MAX_WIDTH-1) {
			posH++;
			posW--;
			direction = DIR_LEFT_UP;
			autoMove(direction, player1, player2);
		} else if (posH == 0) {
			return PLAYER2_WIN;
		} else if (posH == player2.getPositionH()) {
			if (posW <= (player2.getPositionW() + PAD_LENGTH) && posW >= (player2.getPositionW() - PAD_LENGTH)) {
				posH++;
				posW--;
				direction = DIR_LEFT_UP;
			}
		}
	default:
		return GAME_ON;
	}
	return GAME_ON;
}