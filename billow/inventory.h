/*
** EPITECH PROJECT, 2018
** inventory.h
** File description:
** Header file that defines the inventory strutures
*/

#ifndef INVENTORY_H_
	#define INVENTORY_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct inventory inventory;
struct inventory {
	sfTexture *text;
	sfSprite *spr;
	char *name;
	char *desc;
	int quantity;
	int id;
	inventory *next;
};

typedef struct inventory_list inventory_list;
struct inventory_list {
	inventory *first;
};

#endif /* !INVENTORY_H_ */
