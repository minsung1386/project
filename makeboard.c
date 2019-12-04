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
	printf("┌────────────────────────┐");
	for (int i = 1; i < 13; i++) {
		gotoxy(BOARD_POS_X, BOARD_POS_Y + i);
		printf("│                        │");
	}
	gotoxy(BOARD_POS_X, BOARD_POS_Y + 13);
	printf("└────────────────────────┘");
	gotoxy(BOARD_POS_X, BOARD_POS_Y + 16);
	printf("Score : %d", cur_score);
}
void draw(void) {
	int i, j;
	int num;
	for (i = 0; i < BOARD_SIZE; i++) {
		for (j = 0; j < BOARD_SIZE; j++) {
			gotoxy(BOARD_POS_X + j * 6, BOARD_POS_Y + i * 3);
			if (board[i][j] == 0) {		//블럭에 숫자 없음
				gotoxy(BOARD_POS_X + j * 6 + 2, BOARD_POS_Y + i * 3 + 1);	//칸 하나당 6(가로) x 3(세로)
				printf("┌───┐");
				gotoxy(BOARD_POS_X + j * 6 + 2, BOARD_POS_Y + i * 3 + 2);
				printf("│  X│");
				gotoxy(BOARD_POS_X + j * 6 + 2, BOARD_POS_Y + i * 3 + 3);
				printf("└───┘");
			}
			else {	//블럭에 숫자 존재.
				num = board[i][j];
				gotoxy(BOARD_POS_X + j * 6 + 2, BOARD_POS_Y + i * 3 + 1);
				printf("┌───┐");
				gotoxy(BOARD_POS_X + j * 6 + 2, BOARD_POS_Y + i * 3 + 2);
				printf("│%3d│", num);
				gotoxy(BOARD_POS_X + j * 6 + 2, BOARD_POS_Y + i * 3 + 3);
				printf("└───┘");
			}
		}
	}
}
void newGame(void) {
	system("cls");
	cur_score = 0;


	int i, j;
	for (i = 0; i < BOARD_SIZE; i++) {
		for (j = 0; j < BOARD_SIZE; j++) {
			board[i][j] = 0;
		}
	}
}