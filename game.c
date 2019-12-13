#include <stdio.h>
#include <time.h>
#include <windows.h>
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

    draw(); //draw background
    //draw new_num
    new_num();
    new_num();
    while (is_game_over() != 1)
    {
        int key = getch();
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
        switch (getch())
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

//void move(int key)
//{
//    int i, j;
//    int move;
//    int act;
//    int key = getch();
//    switch (key)
//    {
//    case LEFT:
//
//    case RIGHT:
//
//    case DOWN:
//
//    case UP:
//    }
//}

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
