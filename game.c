#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "game.h"
int score;
void move();
int is_game_over();
void new_num();
void start();
void end();

void start()
{
    score = 0;

    draw_start(); //draw background
    //draw new_num
    new_num();
    new_num();
    while (is_game_over() != 1)
    {
        int key = _getch();
        if (key == ESC)
        {
            end();
        }
        else
        {
            move();
        }
    }
    print_restart();
    while (1)
    {
        switch (_getch())
        {
        case 121:
        case 89:
            start();
            break;
        case 110:
        case 78:
        case ESC:
            end();
        }
    }
}

void move()
{
    int i, j;
    int move=-1;
    int act=0;
    int key = _getch();
    switch (key)
    {
	
    case Q: //left up
		for (;move != 0;) {
			move = 0;
			for (i = 1;i <= 3;i++) { //1번행, 2번행, 3번행을 순서대로 검사 
				for (j = 0;j < 4;j++) { //모든 열을 검사 
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
			if (move != 0) draw();
		}
		break;
    case W: // up
		for (;move != 0;) {
			move = 0;
			for (i = 1;i <= 3;i++) { //1번행, 2번행, 3번행을 순서대로 검사 
				for (j = 0;j < 4;j++) { //모든 열을 검사 
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
			if (move != 0) draw();
		}
		break;
    case E: //right up

    case A: //left
		for (;move != 0;) {     //함수 실행시 movee값이 -1이므로 처음엔 반드시 실행되고 실행후 0으로 변경, 
			move = 0;         //이후 게임판에 변화가 있는 경우에 수치 증가하여 게임판에 변화가 없을때까지 반복 
			for (i = 0;i < 4;i++) {  // 모든행을 검사 
				for (j = 1;j <= 3;j++) { //가장 왼쪽열(0번째열)은 검사할 필요가 없으므로 1~3번열을 순서대로 검사 
					if (board[i][j] == 0 || board[i][j] > 10000) continue; //자기 값이 0 혹은 10000보다 큰 경우,
					if (board[i][j - 1] != 0 && board[i][j - 1] != board[i][j]) continue;
					//자기 왼쪽값이 0이 아니고 자신과 다른 경우 다시 검사(j++은 적용됨)
					if (board[i][j - 1] == 0) board[i][j - 1] = board[i][j]; //자기 왼쪽값이 0인경우 자기값 복사 
					else if (board[i][j] == board[i][j - 1]) { //자기 왼쪽값과 동일한 경우에 
						board[i][j - 1] *= 2; //왼쪽값을 2배로(자기 값을 더하는것과 같음) 
						board[i][j - 1] += 10000; // 임시로 값증가 함수 마지막에 다시 값을 감소시킴 
						score += 2 * (board[i][j]); //점수를 증가     
					}
					board[i][j] = 0; //자기 값은 0으로 지움 
					act++; // action이 있음을 알림(get_key 함수 종료시 판단됨) 
					move++; // mov가 있음을 알림(for문안에서만 사용되고 리셋됨) 
				}   /* 10000을 안더하면 만약 한줄에 값이 2,2,2,2 인 경우 왼쪽키를 누르면 한번에       */
			}       /* 8,0,0,0으로 바뀜.. 10000을 더하고, 값이 10000보다 큰 경우 연산을 하지 않게 하여*/
					/* 2,2,2,2 에서 4,4,0,0으로 바뀜 */
			if (move!= 0) draw();// 게임판 변화가 있는 경우 
		}                      // 제일 바깥 for문을 한번 돌때마다 화면을 그려줌(애니메이션 효과) 
		break;
	case D: //right
		for (;move != 0;) {
			move = 0;
			for (j = 2;j >= 0;j--) { //2번열, 1번열, 0번열을 순서대로 검사. 
				for (i = 0;i < 4;i++) {  // 모든행을 검사
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
	case Z: //left down

	case X: //down
		for (;move != 0;) {
			move = 0;
			for (i = 2;i >= 0;i--) { //2번행, 1번행, 0번행을 순서대로 검사  
				for (j = 0;j < 4;j++) { //모든 열을 검사  
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
			if (move != 0) draw();
		}
		break;
	case C: //right down
		break;
    }
	if (act > 0)
		new_num();
}

void new_num()
{
    srand(time(NULL));
    while (1)
    {
        int new_data = 2 * (rand() % 2 + 1);
        int i = rand() % 3, j = rand() % 3;
        if (board[i][j] == 0)
        {
            board[i][j] = new_data;
            draw();
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
