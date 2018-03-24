/*
** EPITECH PROJECT, 2018
** manage_inventory.c
** File description:
** Functions that manages the inventory chained list
*/

#include "inventory.h"

inventory_list *create_inventory(void)
{
	struct inventory_list *invent = malloc(sizeof(inventory_list));
	struct inventory *element = malloc(sizeof(inventory));

	element->text = NULL;
	element->spr = NULL;
	element->name = NULL;
	element->desc = NULL;
	element->quantity = 0;
	element->id = 0;
	element->next = NULL;
	invent->first = element;
	return (invent);
}

inventory *new_ivnt_obj(char *path, char *name)
{
	struct inventory *new = malloc(sizeof(inventory));

	new->text = sfTexture_createFromFile(path, NULL);
	new->spr = sfSprite_create();
	sfSprite_setTexture(new->spr, new->text, sfTrue);
	new->name = my_strdup(name);
	new->quantity = 1;
	//new->id = get_id(name);
	new->next = NULL;
	return (new);
}

int add_inventory(struct inventory_list *ivnt, char *path, char *name)
{
	struct inventory *new = malloc(sizeof(inventory));
	struct inventory *new2 = malloc(sizeof(inventory));

	if (ivnt->first->name == NULL) {
		ivnt->first = new_ivnt_obj(path, name);
		free(new);
		free(new2);
	} else {
		new = ivnt->first;
		while (new->next != NULL && my_strcmp(new->name, name) != 0)
			new = new->next;
		if (new->next == NULL) {
			new2 = new_ivnt_obj(path, name);
			new->next = new2;
		} else
			new->quantity = new->quantity + 1;
	}
	return (0);
}

int del_inventory(struct inventory_list *ivnt, char *name)
{
	struct inventory *previous = NULL;
	struct inventory *del_list = ivnt->first;

	while (del_list->next != NULL && my_strcmp(name, del_list->name) != 0) {
		previous = del_list;
		del_list = del_list->next;
	}
	if (previous == NULL) {
		if (del_list->quantity == 1) {
			inventory *to_delete = ivnt->first;
			ivnt->first = ivnt->first->next;
			free(to_delete);
			return (0);
		} else {
			del_list->quantity = del_list->quantity - 1;
			return (0);
		}
	}
	if (del_list->next != NULL) {
		if (del_list->quantity == 1) {
			previous->next = del_list->next;
			free(del_list);
			return (0);
		} else {
			del_list->quantity = del_list->quantity - 1;
			return (0);
		}
	}
	return (-1);
}