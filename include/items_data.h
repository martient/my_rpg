/*
** EPITECH PROJECT, 2018
** items_data.h
** File description:
** Header file that contains the item_data typedef
*/

#ifndef ITEMS_DATA_H_
	#define ITEMS_DATA_H_

#include <SFML/Graphics.h>

typedef struct items_data_s items_data_t;
struct items_data_s {
	int id;
	char *name;
	int type;
	float stats;
	int x;
	int y;
	sfTexture *texture;
	sfSprite *sprite;
	items_data_t *next;
};

typedef struct items_data_first_t items_data_first_t;
struct items_data_first_t {
	items_data_t *first;
};

#endif /* !ITEMS_DATA_H_ */
