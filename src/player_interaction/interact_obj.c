/*
** EPITECH PROJECT, 2018
** interact_obj.c
** File description:
** function when interaciton key is pressed
*/

#include "my_rpg.h"

int interact_obj(game_global_t *game)
{
	player_info_t *player = game->player;

	if (player->event->type == 2) {
		player->event->obj->visible = 1;
		player->event->obj->cooldown = 5;
		if (inventory_new_obj(game->invent, player->event->obj->name) == -1)
			printf("Inventory full\n");
		print_inventory(game->invent);
	}
	return (0);
}
