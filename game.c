#include <stdio.h>
#include <time.h>
#include <windows.h>

#define ESC 27
#define LEFT 75
#define UP 72
#define DOWN 80
#define RIGHT 77
int board[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
int score;
void move();
int is_game_over();
void new_num();
void start();
void end();
void get_key();

void start()
{
    score = 0;

    draw_start(); //draw background
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

void move(int key)
{
    int i, j;
    int key = getch();
    switch (key)
    {
    case LEFT:

    case RIGHT:

    case DOWN:

    case UP:
    }
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
