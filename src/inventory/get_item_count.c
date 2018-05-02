/*
** EPITECH PROJECT, 2018
** get_item_count.c
** File description:
** get number of item
*/

#include "my_rpg.h"

int inventory_get_count(game_global_t *game, char *item)
{
	inventory_t *inventory = game->invent->first;

	while (inventory) {
		if (my_strcmp(inventory->name, item) == 0) {
			return (inventory->quantity);
		}
		inventory = inventory->next;
	}
	return (0);
}