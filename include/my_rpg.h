/*
** EPITECH PROJECT, 2018
** my_rpg.h
** File description:
** General Header file
*/

#ifndef MY_RPG_H_
	#define MY_RPG_H_
#include <SFML/Graphics.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define GAME_NAME "Overlord Adventures"
#define DEFAULT_FRAME_RATE 60

typedef struct player_info_t {
	char *name;
	int x;
	int y;
	int zone;
} player_info_t;

typedef struct game_global_t {
	sfRenderWindow *window;
	int frame_rate;
	struct player_info_t *player;
} game_global_t;

game_global_t *__init__(void);
int main(int ac, char *argv[], char *env[]);

#endif /* !MY_RPG_H_ */
