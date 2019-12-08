#ifndef __GAME_H__
#define __GAME_H__

#define ESC 27
#define Q 113
#define W 119
#define E 101
#define A 97
#define D 100
#define Z 122
#define X 120
#define C 99

extern int board[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
extern int cur_score;

void start(void);
void move(void);
int is_game_over(void);
void new_num(void);
void end(void);

#endif