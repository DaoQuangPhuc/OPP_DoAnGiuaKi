#include "Map.h"



Map::Map()
{
	for (int i = 0; i < MAX_HEIGHT; i++) {
		for (int j = 0; j < MAX_WIDTH; j++) {
			if (i == 0 || i == MAX_HEIGHT-1) {
				map[i][j] = WALL_CHAR;
			}
			else if (j == 0 || j == MAX_WIDTH - 1)
			{
				map[i][j] = WALL_CHAR;
			}
			else if (i == MAX_HEIGHT/2) {
				map[i][j] = MIDDLE_MAP_CHAR;
			}
			else {
				map[i][j] = MAP_CHAR;
			}
		}
	}
}

void Map::PrintMap() {
	for (int i = 0; i < MAX_HEIGHT; i++) {
		for (int j = 0; j < MAX_WIDTH; j++) {
			if (map[i][j] == MAP_CHAR) {
				cout << " ";
			}
			else if (map[i][j] == WALL_CHAR) {
				cout << (char)219;
			}
			else if (map[i][j] == MIDDLE_MAP_CHAR) {
				cout << (char)250;
			}
			else if (map[i][j] == PLAYER_CHAR) {
				cout << (char)205;
			}
			else if (map[i][j] == BALL_CHAR) {
				cout << (char)15;
			}
			else {
				cout << " ";
			}
		}
		cout << "\n";
	}
}

void Map::PrintLogicMap() {
	for (int i = 0; i < MAX_HEIGHT; i++) {
		for (int j = 0; j < MAX_WIDTH; j++) {
			cout << map[i][j] << ",";
		}
		cout << "\n";
	}
}

void Map::ResetMap() {
	for (int i = 0; i < MAX_HEIGHT; i++) {
		for (int j = 0; j < MAX_WIDTH; j++) {
			if (i == 0 || i == MAX_HEIGHT-1) {
				map[i][j] = WALL_CHAR;
			}
			else if (j == 0 || j == MAX_WIDTH - 1)
			{
				map[i][j] = WALL_CHAR;
			}
			else if (i == MAX_HEIGHT/2) {
				map[i][j] = MIDDLE_MAP_CHAR;
			}
			else {
				map[i][j] = MAP_CHAR;
			}
		}
	}
}

void Map::SetMapObject(Player player1, Player player2, Ball ball) {
	ResetMap();
	map[player1.getPositionH()][player1.getPositionW()] = PLAYER_CHAR;
	for (int i = 1; i <= PAD_LENGTH; i++) {
		map[player1.getPositionH()][player1.getPositionW() + i] = PLAYER_CHAR;
		map[player1.getPositionH()][player1.getPositionW() - i] = PLAYER_CHAR;
	}

	map[player2.getPositionH()][player2.getPositionW()] = PLAYER_CHAR;
	for (int i = 1; i <= PAD_LENGTH; i++) {
		map[player2.getPositionH()][player2.getPositionW() + i] = PLAYER_CHAR;
		map[player2.getPositionH()][player2.getPositionW() - i] = PLAYER_CHAR;
	}

	map[ball.getPosHeight()][ball.getPosWidth()] = BALL_CHAR;
}