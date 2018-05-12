/*
** EPITECH PROJECT, 2018
** draw_quest.c
** File description:
** function to draw quest 
*/

#include "my_rpg.h"

typedef int (*quests_t)(game_global_t *);

void quest_draw_manager(game_global_t *game)
{
	quests_t quest_list[3] = {no_quest, harvest_draw_quest, no_quest};

	if (game->player->state == 0)
		game->player->state = 2;
	quest_list[game->player->state - 2](game);
}