#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "game.h"
int score;
int chance;//
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
	chance = 3;
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
	int move = -1;
	int act = 0;
	int key = _getch();
	switch (key)
	{

	case Q: //left up
		while (move != 0)
		{
			move = 0;
			//ù��°��
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
			//�ι�°��
			for (int i = 2;i <= 3;i++)
			{
				if (board[i][i-1] == 0 || board[i][i-1] > 10000)
					continue;
				if (board[i][i-1] != board[i -1][i-1-1] && board[i - 1][i-1-1] != 0)
					continue;
				if (board[i -1 ][i-1-1] == 0)
					board[i - 1][i-1-1] = board[i][i-1 ];
				else if (board[i][i-1 ] == board[i -1 ][i-1-1])
				{
					board[i - 1][i-1-1] *= 2;
					board[i - 1][i-1-1] += 10000;
					score += 2 * (board[i][i-1 ]);
				}
				board[i][i-1] = 0;
				act++;
				move++;
			}
			//3��°��
			for (int i = 1;i <= 3;i++) {
				if (board[i][i] == 0 || board[i][i] > 10000)
					continue;
				if (board[i][i] != board[i - 1][i-1] && board[i - 1][i-1] != 0)
					continue;
				if (board[i - 1][i-1] == 0)
					board[i - 1][i-1] = board[i][i];
				else if (board[i][i] == board[i - 1][i-1])
				{
					board[i - 1][i-1] *= 2;
					board[i - 1][i-1] += 10000;
					score += 2 * (board[i][i]);
				}
				board[i][i] = 0;
				act++;
				move++;
			}
			//4��°��
			for (int i = 1;i <=2 ;i++)
			{
				if (board[i][i+1] == 0 || board[i][i+1] > 10000)
					continue;
				if (board[i][i+1] != board[i-1][i] && board[i -1][i] != 0)
					continue;
				if (board[i - 1][i] == 0)
					board[i -1][i] = board[i][i+1];
				else if (board[i][i+1] == board[i - 1][i])
				{
					board[i - 1][i+1] *= 2;
					board[i - 1][i+1] += 10000;
					score += 2 * (board[i][i+1]);
				}
				board[i][i+1] = 0;
				act++;
				move++;
			}

			//5��°��
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
			if (move != 0)
				draw();



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
		while (move != 0)
		{
			move = 0;
			//ù��°��
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
			//�ι�°��
			for (int i = 2;i <= 3;i++)
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
			//3��°��
			for (int i = 1;i <= 3;i++) {
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
			//4��°��
			for (int i = 1;i <= 2;i++)
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

			//5��°��
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
				draw();



		}
		break;
	case A: //left
		for (;move != 0;) {     
			move = 0;          
			for (i = 0;i < 4;i++) {  
				for (j = 1;j <= 3;j++) { 
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
		while (move != 0)
		{
			move = 0;
			//ù��°��
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
			//�ι�°��
			for (int i = 2;i >= 1;i--)
			{
				if (board[i][3 - i + 1] == 0 || board[i][3 - i+1] > 10000)
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
			//3��°��
			for (int i = 2;i >= 0;i--) {
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
			//4��°��
			for (int i = 1;i >= 0;i--)
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

			//5��°��
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
				draw();



		}
		break;
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
			if (move != 0)
				draw();
		}
		break;
	case C: //right down
		while (move != 0)
		{
			move = 0;
			//ù��°��
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
			//�ι�°��
			for (int i = 2;i >= 1;i--)
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
			//3��°��
			for (int i = 2;i >= 0;i--) {
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
			//4��°��
			for (int i = 1;i >= 0;i--)
			{
				if (board[i][i + 1] == 0 || board[i][i + 1] > 10000)
					continue;
				if (board[i][i + 1] != board[i + 1][i+2] && board[i + 1][i+2] != 0)
					continue;
				if (board[i + 1][i+2] == 0)
					board[i + 1][i+2] = board[i][i + 1];
				else if (board[i][i + 1] == board[i + 1][i+2])
				{
					board[i + 1][i + 2] *= 2;
					board[i + 1][i + 2] += 10000;
					score += 2 * (board[i][i + 1]);
				}
				board[i][i + 1] = 0;
				act++;
				move++;
			}

			//5��°��
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
				draw();



		}
		break;
	}
	for (i = 0;i < 4;i++)  //�ӽ÷� �������״� 10000�� ����. 
		for (j = 0;j < 4;j++) {
			if (board[i][j] > 10000)
				board[i][j] -= 10000;
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
