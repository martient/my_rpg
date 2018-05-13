/*
** EPITECH PROJECT, 2018
** item_activated.,c
** File description:
** function when item is activated
*/

#include "my_rpg.h"

typedef int (*item_acti_t)(game_global_t *, items_data_t *);

int item_eat(game_global_t *game, items_data_t *item)
{
	player_info_t *player = game->player;
	if (player->health < player->max_health) {
		printf("%s gives %f\n", item->name , item->stats);
		if ((player->health + (int)item->stats) > player->max_health) {
			player->health = player->max_health;
		} else {
			player->health += (int)item->stats;
		}
		printf("Added %d hp\n", (int)item->stats);
		play_sound(game, "eating");
		inventory_del_obj(game->invent, item->name);
		return (0);
	}
	return (1);
}

int item_activat(game_global_t *game, items_data_t *item)
{
	item_acti_t items_act[3] = {item_eat, NULL, NULL};

	if (items_act[item->type](game, item))
		write(1, "Failed\n", 7);
	return (0);
}