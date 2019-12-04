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
