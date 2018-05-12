/*
** EPITECH PROJECT, 2018
** quest_manager.c
** File description:
** function to handle quests
*/

#include "my_rpg.h"

typedef int (*quests_t)(game_global_t *);

int no_quest(game_global_t *game)
{
	return (0);
}

void quest_manager(game_global_t *game)
{
	player_info_t *player = game->player;
	quests_t quest_list[3] = {no_quest,
	is_harvest_done, is_fallen_done};

	if (player->current_quest_id >= 3) {
		if (quest_list[player->current_quest_id - 2](game) == 0) {
			player->current_quest_id = 0;
		}
	}
}