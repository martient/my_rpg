/*
** EPITECH PROJECT, 2018
** map.h
** File description:
** Header file for the map struct
*/

#ifndef MAP_H_
	#define MAP_H_

#include <SFML/Graphics.h>

typedef struct object_info_t object_info_t;
struct object_info_t {
	char *name;
	int x;
	int y;
	int z;
	int collider;
	int type;
	int visible;
	double cooldown;
	sfTexture *texture;
	sfSprite *sprite;
	object_info_t *next;
};

typedef struct object_first_t object_first_t;
struct object_first_t {
	object_info_t *first;
};

typedef struct map_info_t map_info_t;
struct map_info_t {
	char *name;
	int width;
	int height;
	int start_x;
	int start_y;
	object_first_t *first;
};

map_info_t *rpg_map_info(void);

#endif /* !MAP_H_ */
