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

typedef struct inventory_s inventory_t;
struct inventory_s {
	sfTexture *text;
	sfSprite *spr;
	char *name;
	char *desc;
	int quantity;
	int id;
	int y;
	int x;
	inventory_t *next;
};

typedef struct inventory_list_s inventory_list_t;
struct inventory_list_s {
	inventory_t *first;
};

#ifndef LIMIT_INVENTORY_1
#define LIMIT_INVENTORY_1 10
#endif

#ifndef LIMIT_INVENTORY_2
#define LIMIT_INVENTORY_2 20
#endif

#ifndef LIMIT_INVENTORY_3
#define LIMIT_INVENTORY_3 30
#endif

int inventory_new_obj(inventory_list_t *list, char *name);
int inventory_del_obj(inventory_list_t *list, char *name);
int print_inventory(inventory_list_t *ivnt);
inventory_t *new_ivnt_obj(char *path, char *name);
int add_inventory(inventory_list_t *ivnt, char *name);
int del_beginning(inventory_list_t *ivnt, inventory_t *del_list);
int del_end(inventory_t *del, inventory_t *previous);
int del_inventory(inventory_list_t *ivnt, char *name);
inventory_list_t *init_inventory(void);
int get_inventory_size(inventory_list_t *ivnt);

#endif /* !INVENTORY_H_ */
