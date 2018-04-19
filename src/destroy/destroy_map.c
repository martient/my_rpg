/*
** EPITECH PROJECT, 2018
** destroy_map.c
** File description:
** Destroys Map once game is done
*/

#include "my_rpg.h"

int destroy_map(game_global_t *game)
{
	object_info_t *map = game->info_map->first->first;
	object_info_t *bck;

	while (map) {
		sfTexture_destroy(map->texture);
		bck = map;
		map = map->next;
		free(bck);
	}
	return (0);
}