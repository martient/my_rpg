/*
** EPITECH PROJECT, 2018
** mobs_data.h
** File description:
** Header file for the mobs data
*/

#ifndef MOBS_DATA_H_
	#define MOBS_DATA_H_

#include <SFML/Graphics.h>

typedef struct mob_data_t mob_data_t;
struct mob_data_t {
	int id;
	char *name;
	float attack_base;
	float attack_grow;
	float healt_base;
	float healt_grow;
	float armor_base;
	float armor_grow;
	float speed;
	sfTexture *texture;
	sfSprite *sprite;
	mob_data_t *next;
};

typedef struct mob_data_first_t mob_data_first_t;
struct mob_data_first_t {
	mob_data_t *first;
};

#endif /* !MOBS_DATA_H_ */
