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

#ifndef LIMIT_INVENTORY_1
#define LIMIT_INVENTORY_1 10
#endif

#ifndef LIMIT_INVENTORY_2
#define LIMIT_INVENTORY_2 20
#endif

#ifndef LIMIT_INVENTORY_3
#define LIMIT_INVENTORY_3 30
#endif

int inventory_new_obj(struct inventory_list *list, char *name);
int inventory_del_obj(struct inventory_list *list, char *name);
int print_inventory(inventory_list *ivnt);
inventory *new_ivnt_obj(char *path, char *name);
int add_inventory(struct inventory_list *ivnt, char *name);
int del_beginning(inventory_list *ivnt, inventory *del_list);
int del_end(inventory *del, inventory *previous);
int del_inventory(struct inventory_list *ivnt, char *name);
inventory_list *init_inventory(void);
int get_inventory_size(struct inventory_list *ivnt);

#endif /* !INVENTORY_H_ */
