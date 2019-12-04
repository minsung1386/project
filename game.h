#ifndef __GAME_H__
#define __GAME_H__

#define ESC 27
#define LEFT 75
#define UP 72
#define DOWN 80
#define RIGHT 77

extern int board[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
extern int cur_score;

void start(void);
void move(void);
int is_game_over(void);
void new_num(void);
void end(void);

#endif