#include <stdio.h>
#include <time.h>
#include <math.h>
#include <Windows.h>
#include <conio.h>
#include "game.h"

#define BOARD_SIZE 4
#define BOARD_POS_X 10
#define BOARD_POS_Y 5

int board[BOARD_SIZE][BOARD_SIZE];
int score;
int high_score;
int chance;

void gotoxy(int x, int y);
void removeCursor(void);
void initGame(void);
void initBoard(void);
void draw_Score(void);
void draw_Chance(void);
void draw(void);
void newGame(void);
void move(int key);
int is_game_over(void);
void new_num(void);
void start(void);
void end(void);

main() {
    start();
}

void gotoxy(int x, int y) {
    COORD Pos = { x,y };
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
    //generate first two random number
    new_num();
    new_num();
}
void initBoard(void) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++)
            board[i][j] = 0;
    }
	gotoxy(BOARD_POS_X, BOARD_POS_Y);
	printf("┌────────────────────────┐");
	for (int i = 1; i < 13; i++) {
		gotoxy(BOARD_POS_X, BOARD_POS_Y + i);
		printf("│                        │");
	}
	gotoxy(BOARD_POS_X, BOARD_POS_Y + 13);
	printf("└────────────────────────┘");
    draw_Score();
    draw_Chance();
}
void draw_Score(void) {
    gotoxy(BOARD_POS_X + 2, BOARD_POS_Y + 16);
    printf("Score : %d", score);
}
void draw_Chance(void) {
    gotoxy(BOARD_POS_X + 2, BOARD_POS_Y + 15);
    if (chance == 0)
        printf("There is no chance!!");
    else
        printf("Chance : %d left", chance);
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
				printf("│   │");
				gotoxy(BOARD_POS_X + j * 6 + 2, BOARD_POS_Y + i * 3 + 3);
				printf("└───┘");
			}
			else {	//블럭에 숫자 존재.
				num = board[i][j];
                if (num > 10000)num -= 10000;
				gotoxy(BOARD_POS_X + j * 6 + 2, BOARD_POS_Y + i * 3 + 1);
				printf("┌───┐");
				gotoxy(BOARD_POS_X + j * 6 + 2, BOARD_POS_Y + i * 3 + 2);
                printf("│%3d│", num);
				gotoxy(BOARD_POS_X + j * 6 + 2, BOARD_POS_Y + i * 3 + 3);
				printf("└───┘");
			}
		}
	}
    draw_Score();
    draw_Chance();
}
void newGame(void) {
	system("cls");
	score = 0;
	int i, j;
	for (i = 0; i < BOARD_SIZE; i++) {
		for (j = 0; j < BOARD_SIZE; j++) {
			board[i][j] = 0;
		}
	}
}
void start()
{
START_LOOP:
    /*****initailize******/
    score = 0;
	chance = 5;
    system("cls");
    initGame();
    draw();
    /*********************/
    int key;
    while (is_game_over() != 1)
    {
        key = _getch();
        if (key == ESC)
        {
            end();            //game end.
        }
        else
        {
            move(key);
        }
    }
    gotoxy(BOARD_POS_X + 28, BOARD_POS_Y);
    printf("Game Over..                             ");
    gotoxy(BOARD_POS_X + 28, BOARD_POS_Y + 2);
    printf("                                        ");
    gotoxy(BOARD_POS_X + 28, BOARD_POS_Y + 2);
    printf("Restart? (Y/N:quit)");
    while (1)
    {
        switch (_getch())
        {
        case 121:   //y
            goto START_LOOP;
        case 89:    //Y
            goto START_LOOP;
        case 110:   //n
            end();
        case 78:    //N
            end();
        case ESC:
            end();
        }
    }
}
void move(int key)
{
    int i, j;
    int move = -1;
    int act = 0;
   
    switch (key)
    {
    case UPPER_LEFT: //left up(q)
        while (move != 0&&chance>0)
        {
            move = 0;
            //첫번째줄
            while (1)
            {
                if (board[3][1] != 0 && board[3][1] == board[2][0])
                {
                    board[3][1] = 0;
                    board[2][0] *= 2;
                    move++;
                    act++;
                    break;
                }
                if (board[2][0] == 0 && board[3][1] != 0)
                {
                    board[2][0] = board[3][1];
                    board[3][1] = 0;
                    move++;
                    act++;
                    break;
                }
                break;

            }
            //두번째줄
            for (i = 2; i <= 3; i++)
            {
                if (board[i][i - 1] == 0 || board[i][i - 1] > 10000)
                    continue;
                if (board[i][i - 1] != board[i - 1][i - 1 - 1] && board[i - 1][i - 1 - 1] != 0)
                    continue;
                if (board[i - 1][i - 1 - 1] == 0)
                    board[i - 1][i - 1 - 1] = board[i][i - 1];
                else if (board[i][i - 1] == board[i - 1][i - 1 - 1])
                {
                    board[i - 1][i - 1 - 1] *= 2;
                    board[i - 1][i - 1 - 1] += 10000;
                    score += 2 * (board[i][i - 1]);
                }
                board[i][i - 1] = 0;
                act++;
                move++;
            }
            //3번째줄
            for (i = 1; i <= 3; i++) {
                if (board[i][i] == 0 || board[i][i] > 10000)
                    continue;
                if (board[i][i] != board[i - 1][i - 1] && board[i - 1][i - 1] != 0)
                    continue;
                if (board[i - 1][i - 1] == 0)
                    board[i - 1][i - 1] = board[i][i];
                else if (board[i][i] == board[i - 1][i - 1])
                {
                    board[i - 1][i - 1] *= 2;
                    board[i - 1][i - 1] += 10000;
                    score += 2 * (board[i][i]);
                }
                board[i][i] = 0;
                act++;
                move++;
            }
            //4번째줄
            for (i = 1; i <= 2; i++)
            {
                if (board[i][i + 1] == 0 || board[i][i + 1] > 10000)
                    continue;
                if (board[i][i + 1] != board[i - 1][i] && board[i - 1][i] != 0)
                    continue;
                if (board[i - 1][i] == 0)
                    board[i - 1][i] = board[i][i + 1];
                else if (board[i][i + 1] == board[i - 1][i])
                {
                    board[i - 1][i + 1] *= 2;
                    board[i - 1][i + 1] += 10000;
                    score += 2 * (board[i][i + 1]);
                }
                board[i][i + 1] = 0;
                act++;
                move++;
            }

            //5번째줄
            while (1)
            {
				
                if (board[1][3] != 0 && board[1][3] == board[0][2])
                {
                    board[1][3] = 0;
                    board[0][2] *= 2;
                    move++;
                    act++;
                    break;
                }
                if (board[0][2] == 0 && board[1][3] != 0)
                {
                    board[0][2] = board[1][3];
                    board[1][3] = 0;
                    move++;
                    act++;
                    break;
                }
                break;

            }
            if (move != 0) {
                draw();
            }
        }
        chance--;
        break;
    case UP: // up
        for (; move != 0;) {
            move = 0;
            for (i = 1; i <= 3; i++) { //1번행, 2번행, 3번행을 순서대로 검사 
                for (j = 0; j < 4; j++) { //모든 열을 검사 
                    if (board[i][j] == 0 || board[i][j] > 10000) continue;
                    if (board[i - 1][j] != 0 && board[i - 1][j] != board[i][j]) continue;
                    if (board[i - 1][j] == 0) board[i - 1][j] = board[i][j];
                    else if (board[i][j] < 10000 && board[i][j] == board[i - 1][j]) {
                        board[i - 1][j] *= 2;
                        board[i - 1][j] += 10000;
                        score += 2 * (board[i][j]);
                    }
                    board[i][j] = 0;
                    act++;
                    move++;
                }
            }
			if (move != 0) {
				draw();
			}
        }
        break;
    case UPPER_RIGHT: //right up(e)
        while (move != 0 && chance > 0)
        {
            move = 0;
            //첫번째줄
            while (1)
            {
                if (board[3][2] != 0 && board[3][2] == board[2][3])
                {
                    board[3][2] = 0;
                    board[2][3] *= 2;
                    move++;
                    act++;
                    break;
                }
                if (board[2][3] == 0 && board[3][2] != 0)
                {
                    board[2][3] = board[3][2];
                    board[3][2] = 0;
                    move++;
                    act++;
                    break;
                }
                break;

            }
            //두번째줄
            for (int i = 2; i <= 3; i++)
            {
                if (board[i][3 - i + 1] == 0 || board[i][3 - i + 1] > 10000)
                    continue;
                if (board[i][3 - i + 1] != board[i - 1][3 - i + 2] && board[i - 1][3 - i + 2] != 0)
                    continue;
                if (board[i - 1][3 - i + 2] == 0)
                    board[i - 1][3 - i + 2] = board[i][3 - i + 1];
                else if (board[i][3 - i + 1] == board[i - 1][3 - i + 2])
                {
                    board[i - 1][3 - i + 2] *= 2;
                    board[i - 1][3 - i + 2] += 10000;
                    score += 2 * (board[i][3 - i + 1]);
                }
                board[i][3 - i + 1] = 0;
                act++;
                move++;
            }
            //3번째줄
            for (int i = 1; i <= 3; i++) {
                if (board[i][3 - i] == 0 || board[i][3 - i] > 10000)
                    continue;
                if (board[i][3 - i] != board[i - 1][3 - i + 1] && board[i - 1][3 - i + 1] != 0)
                    continue;
                if (board[i - 1][3 - i + 1] == 0)
                    board[i - 1][3 - i + 1] = board[i][3 - i];
                else if (board[i][3 - i] == board[i - 1][3 - i + 1])
                {
                    board[i - 1][3 - i + 1] *= 2;
                    board[i - 1][3 - i + 1] += 10000;
                    score += 2 * (board[i][3 - i]);
                }
                board[i][3 - i] = 0;
                act++;
                move++;
            }
            //4번째줄
            for (int i = 1; i <= 2; i++)
            {
                if (board[i][3 - i - 1] == 0 || board[i][3 - i - 1] > 10000)
                    continue;
                if (board[i][3 - i - 1] != board[i - 1][3 - i] && board[i - 1][3 - i] != 0)
                    continue;
                if (board[i - 1][3 - i] == 0)
                    board[i - 1][3 - i] = board[i][3 - i - 1];
                else if (board[i][3 - i - 1] == board[i - 1][3 - i])
                {
                    board[i - 1][3 - i] *= 2;
                    board[i - 1][3 - i] += 10000;
                    score += 2 * (board[i][3 - i - 1]);
                }
                board[i][3 - i - 1] = 0;
                act++;
                move++;
            }

            //5번째줄
            while (1)
            {
                if (board[1][0] != 0 && board[1][0] == board[0][1])
                {
                    board[1][0] = 0;
                    board[0][1] *= 2;
                    move++;
                    act++;
                    break;
                }
                if (board[0][1] == 0 && board[1][0] != 0)
                {
                    board[0][1] = board[1][0];
                    board[1][0] = 0;
                    move++;
                    act++;
                    break;
                }
                break;

            }
            if (move != 0)
            {
                draw();
            }
        }
        chance--;
        break;
    case LEFT: //left
        for (; move != 0;) {
            move = 0;
            for (i = 0; i < 4; i++) {
                for (j = 1; j <= 3; j++) {
                    if (board[i][j] == 0 || board[i][j] > 10000) continue;
                    if (board[i][j - 1] != 0 && board[i][j - 1] != board[i][j]) continue;
                    if (board[i][j - 1] == 0) board[i][j - 1] = board[i][j];
                    else if (board[i][j] == board[i][j - 1]) {
                        board[i][j - 1] *= 2;
                        board[i][j - 1] += 10000;
                        score += 2 * (board[i][j]);
                    }
                    board[i][j] = 0;
                    act++;
                    move++;
                }
            }

            if (move != 0)
                draw();
        }
        break;
    case RIGHT: //right
        for (; move != 0;) {
            move = 0;
            for (j = 2; j >= 0; j--) { //2번열, 1번열, 0번열을 순서대로 검사. 
                for (i = 0; i < 4; i++) {  // 모든행을 검사
                    if (board[i][j] == 0 || board[i][j] > 10000) continue;
                    if (board[i][j + 1] != 0 && board[i][j + 1] != board[i][j]) continue;
                    if (board[i][j + 1] == 0) board[i][j + 1] = board[i][j];
                    else if (board[i][j] < 10000 && board[i][j] == board[i][j + 1]) {
                        board[i][j + 1] *= 2;
                        board[i][j + 1] += 10000;
                        score += 2 * (board[i][j]);
                    }
                    board[i][j] = 0;
                    move++;
                    act++;
                }
            }
            if (move != 0) draw();
        }
        break;
    case LOWER_LEFT: //left down(z)
        while (move != 0&&chance>0)
        {
            move = 0;
            //첫번째줄
            while (1)
            {
                if (board[2][3] != 0 && board[3][2] == board[2][3])
                {
                    board[2][3] = 0;
                    board[3][2] *= 2;
                    move++;
                    act++;
                    break;
                }
                if (board[3][2] == 0 && board[2][3] != 0)
                {
                    board[3][2] = board[2][3];
                    board[2][3] = 0;
                    move++;
                    act++;
                    break;
                }
                break;

            }
            //두번째줄
            for (int i = 2; i >= 1; i--)
            {
                if (board[i][3 - i + 1] == 0 || board[i][3 - i + 1] > 10000)
                    continue;
                if (board[i][3 - i + 1] != board[i + 1][3 - i] && board[i + 1][3 - i] != 0)
                    continue;
                if (board[i + 1][3 - i] == 0)
                    board[i + 1][3 - i] = board[i][3 - i + 1];
                else if (board[i][3 - i + 1] == board[i + 1][3 - i])
                {
                    board[i + 1][3 - i] *= 2;
                    board[i + 1][3 - i] += 10000;
                    score += 2 * (board[i][3 - i + 1]);
                }
                board[i][3 - i + 1] = 0;
                act++;
                move++;
            }
            //3번째줄
            for (int i = 2; i >= 0; i--) {
                if (board[i][3 - i] == 0 || board[i][3 - i] > 10000)
                    continue;
                if (board[i][3 - i] != board[i + 1][3 - i - 1] && board[i + 1][3 - i - 1] != 0)
                    continue;
                if (board[i + 1][3 - i - 1] == 0)
                    board[i + 1][3 - i - 1] = board[i][3 - i];
                else if (board[i][3 - i] == board[i + 1][3 - i - 1])
                {
                    board[i + 1][3 - i - 1] *= 2;
                    board[i + 1][3 - i - 1] += 10000;
                    score += 2 * (board[i][3 - i]);
                }
                board[i][3 - i] = 0;
                act++;
                move++;
            }
            //4번째줄
            for (int i = 1; i >= 0; i--)
            {
                if (board[i][3 - i - 1] == 0 || board[i][3 - i - 1] > 10000)
                    continue;
                if (board[i][3 - i - 1] != board[i + 1][3 - i - 2] && board[i + 1][3 - i - 2] != 0)
                    continue;
                if (board[i + 1][3 - i - 2] == 0)
                    board[i + 1][3 - i - 2] = board[i][3 - i - 1];
                else if (board[i][3 - i - 1] == board[i + 1][3 - i - 2])
                {
                    board[i + 1][3 - i - 2] *= 2;
                    board[i + 1][3 - i - 2] += 10000;
                    score += 2 * (board[i][3 - i - 1]);
                }
                board[i][3 - i - 1] = 0;
                act++;
                move++;
            }

            //5번째줄
            while (1)
            {
                if (board[0][1] != 0 && board[0][1] == board[1][0])
                {
                    board[0][1] = 0;
                    board[1][0] *= 2;
                    move++;
                    act++;
                    break;
                }
                if (board[1][0] == 0 && board[0][1] != 0)
                {
                    board[1][0] = board[0][1];
                    board[0][1] = 0;
                    move++;
                    act++;
                    break;
                }
                break;

            }
			if (move != 0)
			{
				draw();
			}
        }
        chance--;
        break;
    case DOWN: //down
        for (; move != 0;) {
            move = 0;
            for (i = 2; i >= 0; i--) { //2번행, 1번행, 0번행을 순서대로 검사  
                for (j = 0; j < 4; j++) { //모든 열을 검사  
                    if (board[i][j] == 0 || board[i][j] > 10000) continue;
                    if (board[i + 1][j] != 0 && board[i + 1][j] != board[i][j]) continue;
                    if (board[i + 1][j] == 0) board[i + 1][j] = board[i][j];
                    else if (board[i][j] < 10000 && board[i][j] == board[i + 1][j]) {
                        board[i + 1][j] *= 2;
                        board[i + 1][j] += 10000;
                        score += 2 * (board[i][j]);
                    }
                    board[i][j] = 0;
                    act++;
                    move++;
                }
            }
            if (move != 0)
                draw();
        }
        break;
    case LOWER_RIGHT: //right down(c)
        while (move != 0&&chance>0)
        {
            move = 0;
            //첫번째줄
            while (1)
            {
                if (board[2][0] != 0 && board[2][0] == board[3][1])
                {
                    board[2][0] = 0;
                    board[3][1] *= 2;
                    move++;
                    act++;
                    break;
                }
                if (board[3][1] == 0 && board[2][0] != 0)
                {
                    board[3][1] = board[2][0];
                    board[2][0] = 0;
                    move++;
                    act++;
                    break;
                }
                break;

            }
            //두번째줄
            for (int i = 2; i >= 1; i--)
            {
                if (board[i][i - 1] == 0 || board[i][i - 1] > 10000)
                    continue;
                if (board[i][i - 1] != board[i + 1][i] && board[i + 1][i] != 0)
                    continue;
                if (board[i + 1][i] == 0)
                    board[i + 1][i] = board[i][i - 1];
                else if (board[i][i - 1] == board[i + 1][i])
                {
                    board[i + 1][i] *= 2;
                    board[i + 1][i] += 10000;
                    score += 2 * (board[i][i - 1]);
                }
                board[i][i - 1] = 0;
                act++;
                move++;
            }
            //3번째줄
            for (int i = 2; i >= 0; i--) {
                if (board[i][i] == 0 || board[i][i] > 10000)
                    continue;
                if (board[i][i] != board[i + 1][i + 1] && board[i + 1][i + 1] != 0)
                    continue;
                if (board[i + 1][i + 1] == 0)
                    board[i + 1][i + 1] = board[i][i];
                else if (board[i][i] == board[i + 1][i + 1])
                {
                    board[i + 1][i + 1] *= 2;
                    board[i + 1][i + 1] += 10000;
                    score += 2 * (board[i][i]);
                }
                board[i][i] = 0;
                act++;
                move++;
            }
            //4번째줄
            for (int i = 1; i >= 0; i--)
            {
                if (board[i][i + 1] == 0 || board[i][i + 1] > 10000)
                    continue;
                if (board[i][i + 1] != board[i + 1][i + 2] && board[i + 1][i + 2] != 0)
                    continue;
                if (board[i + 1][i + 2] == 0)
                    board[i + 1][i + 2] = board[i][i + 1];
                else if (board[i][i + 1] == board[i + 1][i + 2])
                {
                    board[i + 1][i + 2] *= 2;
                    board[i + 1][i + 2] += 10000;
                    score += 2 * (board[i][i + 1]);
                }
                board[i][i + 1] = 0;
                act++;
                move++;
            }

            //5번째줄
            while (1)
            {
                if (board[0][2] != 0 && board[0][2] == board[1][3])
                {
                    board[0][2] = 0;
                    board[1][3] *= 2;
                    move++;
                    act++;
                    break;
                }
                if (board[1][3] == 0 && board[0][2] != 0)
                {
                    board[1][3] = board[0][2];
                    board[0][2] = 0;
                    move++;
                    act++;
                    break;
                }
                break;

            }
            if (move != 0)
            {
                draw();
            }
        }
        chance--;
        break;
    }
    for (i = 0; i < 4; i++) {  //임시로 증가시켰던 10000을 빼줌. 
        for (j = 0; j < 4; j++) {
            if (board[i][j] > 10000)
                board[i][j] -= 10000;
        }
    }
    if (act > 0)
        new_num();
    draw();
}
void new_num()
{
    int i, j;
    srand((unsigned)time(NULL));
    while (1)
    {
        int new_data = 2 * (rand() % 2 + 1);
        i = rand() % BOARD_SIZE, j = rand() % BOARD_SIZE;
        if (board[i][j] == 0)
        {
            board[i][j] = new_data;
            break;
        }
    }
}
int is_game_over()
{
    int i, j;
    //1. have an empty slot
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            if (board[i][j] == 0)
                return 0;
    //2. there are some data that can combine
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (board[i][j] == board[i + 1][j] || board[i][j] == board[i][j + 1])
                return 0;
    for (i = 0; i < 3; i++)
        if (board[i][3] == board[i + 1][3])
            return 0;
    for (j = 0; j < 3; j++)
        if (board[3][j] == board[3][j + 1])
            return 0;
    return 1;
}
void end()
{
    exit(0);
}