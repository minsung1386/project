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
			for (i = 1;i <= 3;i++) { //1����, 2����, 3������ ������� �˻� 
				for (j = 0;j < 4;j++) { //��� ���� �˻� 
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
			for (i = 1;i <= 3;i++) { //1����, 2����, 3������ ������� �˻� 
				for (j = 0;j < 4;j++) { //��� ���� �˻� 
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
		for (;move != 0;) {     //�Լ� ����� movee���� -1�̹Ƿ� ó���� �ݵ�� ����ǰ� ������ 0���� ����, 
			move = 0;         //���� �����ǿ� ��ȭ�� �ִ� ��쿡 ��ġ �����Ͽ� �����ǿ� ��ȭ�� ���������� �ݺ� 
			for (i = 0;i < 4;i++) {  // ������� �˻� 
				for (j = 1;j <= 3;j++) { //���� ���ʿ�(0��°��)�� �˻��� �ʿ䰡 �����Ƿ� 1~3������ ������� �˻� 
					if (board[i][j] == 0 || board[i][j] > 10000) continue; //�ڱ� ���� 0 Ȥ�� 10000���� ū ���,
					if (board[i][j - 1] != 0 && board[i][j - 1] != board[i][j]) continue;
					//�ڱ� ���ʰ��� 0�� �ƴϰ� �ڽŰ� �ٸ� ��� �ٽ� �˻�(j++�� �����)
					if (board[i][j - 1] == 0) board[i][j - 1] = board[i][j]; //�ڱ� ���ʰ��� 0�ΰ�� �ڱⰪ ���� 
					else if (board[i][j] == board[i][j - 1]) { //�ڱ� ���ʰ��� ������ ��쿡 
						board[i][j - 1] *= 2; //���ʰ��� 2���(�ڱ� ���� ���ϴ°Ͱ� ����) 
						board[i][j - 1] += 10000; // �ӽ÷� ������ �Լ� �������� �ٽ� ���� ���ҽ�Ŵ 
						score += 2 * (board[i][j]); //������ ����     
					}
					board[i][j] = 0; //�ڱ� ���� 0���� ���� 
					act++; // action�� ������ �˸�(get_key �Լ� ����� �Ǵܵ�) 
					move++; // mov�� ������ �˸�(for���ȿ����� ���ǰ� ���µ�) 
				}   /* 10000�� �ȴ��ϸ� ���� ���ٿ� ���� 2,2,2,2 �� ��� ����Ű�� ������ �ѹ���       */
			}       /* 8,0,0,0���� �ٲ�.. 10000�� ���ϰ�, ���� 10000���� ū ��� ������ ���� �ʰ� �Ͽ�*/
					/* 2,2,2,2 ���� 4,4,0,0���� �ٲ� */
			if (move!= 0) draw();// ������ ��ȭ�� �ִ� ��� 
		}                      // ���� �ٱ� for���� �ѹ� �������� ȭ���� �׷���(�ִϸ��̼� ȿ��) 
		break;
	case D: //right
		for (;move != 0;) {
			move = 0;
			for (j = 2;j >= 0;j--) { //2����, 1����, 0������ ������� �˻�. 
				for (i = 0;i < 4;i++) {  // ������� �˻�
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
			for (i = 2;i >= 0;i--) { //2����, 1����, 0������ ������� �˻�  
				for (j = 0;j < 4;j++) { //��� ���� �˻�  
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
