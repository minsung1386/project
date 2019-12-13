#ifndef __GAME_H__
#define __GAME_H__

#define ESC 27
#define Q 113
//#define W 119
#define W 72
#define E 101
//#define A 97
#define A 75
//#define D 100
#define D 77
#define Z 122
//#define X 120
#define X 80
#define C 99

extern int cur_score;

void start(void);
void move(void);
int is_game_over(void);
void new_num(void);
void end(void);

#endif