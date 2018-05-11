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
		player->event->obj->cooldown = 30;
	}
	if (player->event->type >= 3)
		player->current_quest_id = player->event->type;
	return (0);
}
