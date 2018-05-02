/*
** EPITECH PROJECT, 2018
** obj_cooldown.c
** File description:
** handle objects cooldown
*/

#include "my_rpg.h"

int obj_cooldown(game_global_t *game, double sec)
{
	object_info_t *map = game->info_map->first->first;

	while (map) {
		if (map->cooldown > 0) {
			map->cooldown -= sec * 4;
		}
		if (map->cooldown < 0)
			map->cooldown = 0;
		if (map->cooldown == 0)
			map->visible = 0;
		map = map->next;
	}
	return (0);
}