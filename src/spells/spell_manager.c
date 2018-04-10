/*
** EPITECH PROJECT, 2018
** spell_manager.c
** File description:
** function to manage spells
*/

#include "my_rpg.h"

void spell_cooldown(game_global_t *game, double delta_time)
{
	player_info_t *player = game->player;
	double sec = sfTime_asSeconds(sfClock_getElapsedTime(game->clock));

	for (int i = 0; i < 5; i++) {
		if (player->spell_cd[i] > 0)
			player->spell_cd[i] -= sec * 4;
		if (player->spell_cd[i] < 0)
			player->spell_cd[i] = 0;
	}
}

void activate_spell(game_global_t *game, int spell)
{
	player_info_t *player = game->player;

	if (player->spell_cd[spell] <= 0) {
		player->spell_cd[spell] = 5;
	}
}