/*
** EPITECH PROJECT, 2018
** manage_inventory.c
** File description:
** Functions that manages the inventory chained list
*/

#include "my_rpg.h"

inventory_t *new_ivnt_obj(char *path, char *name)
{
	inventory_t *new = malloc(sizeof(inventory));

	if (path != NULL) {
		new->text = sfTexture_createFromFile(path, NULL);
		new->spr = sfSprite_create();
		sfSprite_setTexture(new->spr, new->text, sfTrue);
	}
	new->name = my_strdup(name);
	new->quantity = 1;
	//new->id = get_id(name);
	new->next = NULL;
	return (new);
}

int add_inventory(inventory_list_t *ivnt, char *name)
{
	inventory_t *new = malloc(sizeof(inventory));
	inventory_t *new2 = malloc(sizeof(inventory));

	if (ivnt->first->name == NULL) {
		ivnt->first = new_ivnt_obj(NULL, name);
		free(new);
		free(new2);
	} else {
		new = ivnt->first;
		while (new->next != NULL && my_strcmp(new->name, name) != 0)
			new = new->next;
		if (new->next == NULL && my_strcmp(new->name, name) != 0) {
			new2 = new_ivnt_obj(NULL, name);
			new->next = new2;
		} else
			new->quantity = new->quantity + 1;
	}
	return (0);
}

int del_beginning(inventory_list_t *ivnt, inventory_t *del_list)
{
	if (del_list->quantity == 1) {
		inventory *to_delete = ivnt->first;
		ivnt->first = ivnt->first->next;
		free(to_delete);
	} else {
		del_list->quantity = del_list->quantity - 1;
	}
	return (0);
}

int del_end(inventory_t *del, inventory_t *previous)
{
	if (del->quantity == 1) {
		previous->next = del->next;
		free(del);
	} else {
		del->quantity = del->quantity - 1;
	}
	return (0);
}

int del_inventory(inventory_list_t *ivnt, char *name)
{
	inventory_t *previous = NULL;
	inventory_t *del = ivnt->first;

	while (del->next != NULL && my_strcmp(name, del->name) != 0) {
		previous = del;
		del = del->next;
	}
	if (previous == NULL) {
		return (del_beginning(ivnt, del));
	}
	if (del->next != NULL) {
		return (del_end(del, previous));
	}
	if (del->next == NULL && del->name != NULL) {
		return (del_end(del, previous));
	}
	return (-1);
}
