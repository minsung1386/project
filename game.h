#ifndef __GAME_H__
#define __GAME_H__

#define ESC 27
#define UPPER_LEFT 113
#define UP 72
#define UPPER_RIGHT 101
#define LEFT 75
#define RIGHT 77
#define LOWER_LEFT 122
#define DOWN 80
#define LOWER_RIGHT 99

extern int cur_score;

void start(void);
void move(void);
int is_game_over(void);
void new_num(void);
void end(void);

#endif