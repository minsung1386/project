#include <stdio.h>
#include <time.h>
#include <math.h>
#include <Windows.h>
#include <conio.h>

#define BOARD_SIZE 4
#define BOARD_POS_X 10
#define BOARD_POS_Y 5

int board[BOARD_SIZE][BOARD_SIZE];
int cur_score;
int high_score;

void gotoxy(int x, int y);
void initGame(void);
void removeCursor(void);
void initBoard(void);
void draw(void);
void newGame(void);

main() {
	initGame();
	while (1) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				board[i][j] = i + j;
			}
		}
		draw();
		_getch();
	}
}

void gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void removeCursor(void) {
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
void initGame() {
	removeCursor();
	initBoard();
}
void initBoard(void) {
	gotoxy(BOARD_POS_X, BOARD_POS_Y);
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式忖");
	for (int i = 1; i < 13; i++) {
		gotoxy(BOARD_POS_X, BOARD_POS_Y + i);
		printf("弛                        弛");
	}
	gotoxy(BOARD_POS_X, BOARD_POS_Y + 13);
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式戎");
	gotoxy(BOARD_POS_X, BOARD_POS_Y + 16);
	printf("Score : %d", cur_score);
}
