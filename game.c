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
void move(int key);
int is_game_over();
void restart();
void new_num();
void start();
void end();
void get_key();

void start()
{
    score = 0;

    draw_start(); //draw background
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
            key == getch();
            move(key);
        }
    }
}