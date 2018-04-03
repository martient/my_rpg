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
#include "my.h"
// #include "inventory.h"
#define GAME_NAME "Overlord Adventures"
#define DEFAULT_FRAME_RATE 60
#define START_SCREEN 0

typedef struct player_info_t {
	char *name;
	int x;
	int y;
	int zone;
} player_info_t;

typedef struct object_info_t object_info_t;
struct object_info_t {
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
	object_info_t *next;
};

typedef struct object_first_t object_first_t;
struct object_first_t {
	object_info_t *first;
};

typedef struct game_global_t {
	sfRenderWindow *window;
	int screen_id;
	int frame_rate;
	sfFont *font;
	struct player_info_t *player;
} game_global_t;

game_global_t *__init__(void);
void engine_exit(game_global_t *global);
#endif /* !MY_RPG_H_ */