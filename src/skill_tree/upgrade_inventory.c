/*
** EPITECH PROJECT, 2018
** upgrade_inventory.c
** File description:
** Function that makes you upgrade your inventory
*/

#include "my_rpg.h"

int upgrade_inventory(struct game_global_t *game)
{
	int upgrade = INVENTORY_UPGRADE_COST;

	if (game->tree->invent_size == 3)
		return (-1);
	if (game->player->skill_point < upgrade)
		return (-1);
	game->tree->invent_size = game->tree->invent_size + 1;
	game->player->skill_point = game->player->skill_point - upgrade;
	return (0);
}