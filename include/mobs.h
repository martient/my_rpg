/*
** EPITECH PROJECT, 2018
** mobs.h
** File description:
** Header file for the mobs
*/

#ifndef MOBS_H_
	#define MOBS_H_

#include <SFML/Graphics.h>

typedef struct spawn_mob_t spawn_mob_t;
struct spawn_mob_t {
	int id;
	int y;
	int x;
	int type;
	int rate;
	int size;
	spawn_mob_t *next;
};

typedef struct spawn_first_t spawn_first_t;
struct spawn_first_t {
	spawn_mob_t *first;
};

typedef struct mob_info_t mob_info_t;
struct mob_info_t {
	int id;
	float y;
 	float x;
	int type;
	int agressive;
	int level;
	double health;
	sfSprite *sprite;
	spawn_mob_t *spawn;
	mob_info_t *next;
};

typedef struct mob_first_t mob_first_t;
struct mob_first_t {
	mob_info_t *first;
};

#endif /* !MOBS_H_ */
