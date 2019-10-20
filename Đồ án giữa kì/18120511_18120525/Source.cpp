#include <windows.h>
#include "Map.h"
#include "Player.h"
#include<conio.h>


void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;

	SetConsoleCursorPosition(hOut, Position);
}

int main() {
	SetConsoleTitle(TEXT("PONG GAME"));
	cout << "===== Press Enter to begin =====";
	_getch();
	system("CLS");

	int ballDirection = DIR_LEFT_DOWN;
	int GameStatus = GAME_ON;

	Map map;
	Player player1 = Player(1, MAX_WIDTH/2);
	Player player2 = Player(MAX_HEIGHT-2, MAX_WIDTH/2);
	Ball ball = Ball(10, MAX_WIDTH/2);

	map.SetMapObject(player1, player2, ball);
	map.PrintMap();

	while (GameStatus == GAME_ON)
	{
		if (GetAsyncKeyState('D')) {
			player1.moveRight();
		}
		
		if (GetAsyncKeyState('A')) {
			player1.moveLeft();
		}

		if (GetAsyncKeyState(VK_RIGHT)) {
			player2.moveRight();
		}

		if (GetAsyncKeyState(VK_LEFT)) {
			player2.moveLeft();
		}

		GameStatus = ball.autoMove(ballDirection, player1, player2);
		map.SetMapObject(player1, player2, ball);
		XoaManHinh();
		map.PrintMap();
		Sleep(0);

	}
	
	

	if (GameStatus == PLAYER1_WIN) {
		system("CLS");
		cout << "===== PLAYER 1 WINS !!! =====";
	} else {
		system("CLS");
		cout << "===== PLAYER 2 WINS !!! =====";
	}

	_getch();
	return 0;
}