#include <stdio.h>
#include <time.h>
#include <windows.h>

int board[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

void move();
void is_game_over();
void restart();
void new_num();
void start();
void end();