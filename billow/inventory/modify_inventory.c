/*
** EPITECH PROJECT, 2018
** modify_inventory.c
** File description:
** Function that checks if you can add or remove something in the inventory
*/

#include "inventory.h"

int inventory_new_obj(struct inventory_list_t *list, char *name)
{
	static int limit = LIMIT_INVENTORY_1;

	if (get_inventory_size() >= limit)
		return (-1);
	else
		add_inventory(list, name);
	return (0);
}

int inventory_del_obj(struct inventory_list_t *list, char *name)
{
	return (del_inventory(list, name));
}