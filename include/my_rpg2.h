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
#include "nxjson.h"
// #include "inventory.h"
#define GAME_NAME "Overlord Adventures"
#define DEFAULT_FRAME_RATE 60
#define START_SCREEN 0

typedef struct player_info_t {
	char *name;
	double x;
	double y;
	int zone;
	int health;
	int mana;
	double cd_q;
	double cd_w;
	double cd_e;
	double cd_r;
} player_info_t;

typedef struct object_info_t {
	char *name;
	int x;
	int y;
	int z;
	int collider;
	int type;
	int visible;
	//Collision call back;
	sfTexture *texture;
	sfSprite *sprite;
}object_info_t;

typedef struct object_first_t {
	object_info_t *first;
}object_first_t;

typedef struct game_global_t {
	sfRenderWindow *window;
	sfClock *clock;
	int screen_id;
	int frame_rate;
	int state;
	sfFont *font;
	struct player_info_t *player;
} game_global_t;

game_global_t *__init__(void);
int main(int ac, char *argv[], char *env[]);
void engine_exit(game_global_t *global);
void draw_bar(game_global_t *game, sfColor colors[2], int *infos);
void draw_shim(game_global_t *game, sfColor color);
#endif /* !MY_RPG_H_ */
