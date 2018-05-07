/*
** EPITECH PROJECT, 2018
** get_item_quantity.c
** File description:
** Function that take one item and returns it quantity
*/

#include "global.h"
#include "inventory.h"

int get_item_quantity(game_global_t *game, char *item)
{
	inventory_t *count = malloc(sizeof(inventory_t));

	if (ivnt == NULL)
		return (-1);
	count = ivnt->first;
	while (count != NULL) {
		if (my_strcmp(count->name, item) == 0)
			return (count->quantity);
		count = count->next;
	}
	free(count);
	return (0);
}