/*
** EPITECH PROJECT, 2018
** interact_obj.c
** File description:
** function when interaciton key is pressed
*/

#include "my_rpg.h"

typedef int (*quests_t)(game_global_t *);

int interact_obj(game_global_t *game)
{
	player_info_t *player = game->player;

	if (player->event->type == 2) {
		inventory_new_obj(game, game->player->event->obj->name);
		player->event->obj->visible = 1;
		player->event->obj->cooldown = 30;
	}
	if (player->event->type >= 3) {
		player->current_quest_id = player->event->type;
		player->state = player->current_quest_id;
	}
	return (0);
}
