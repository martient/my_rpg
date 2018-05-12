/*
** EPITECH PROJECT, 2018
** modify_inventory.c
** File description:
** Function that checks if you can add or remove something in the inventory
*/

#include "skill_tree.h"
#include "global.h"
#include "inventory.h"

int get_limit(game_global_t *game)
{
	int limit = 0;

	if (game->tree->invent_size == 1)
		limit = LIMIT_INVENTORY_1;
	if (game->tree->invent_size == 2)
		limit = LIMIT_INVENTORY_2;
	if (game->tree->invent_size == 3)
		limit = LIMIT_INVENTORY_3;
	return (limit);
}

int inventory_new_obj(game_global_t *game, char *name)
{
	int limit = get_limit(game);

	if (get_inventory_size(game->invent) >= limit)
		return (-1);
	else
		add_inventory(game->invent, name);
	return (0);
}

int inventory_del_obj(inventory_list_t *list, char *name)
{
	return (del_inventory(list, name));
}
