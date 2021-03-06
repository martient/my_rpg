/*
** EPITECH PROJECT, 2018
** spell_manager.c
** File description:
** function to manage spells
*/

#include "my_rpg.h"

typedef int (*spell_t)(game_global_t *);

void spell_cooldown(game_global_t *game, double delta_time)
{
	player_info_t *player = game->player;
	double sec = delta_time;

	for (int i = 0; i < 5; i++) {
		if (player->spell_cd[i] > 0)
			player->spell_cd[i] -= sec;
		if (player->spell_cd[i] < 0)
			player->spell_cd[i] = 0;
		if (player->spell_duration[i] > 0)
			player->spell_duration[i] -= sec;
		if (player->spell_duration[i] < 0)
			player->spell_duration[i] = 0;
		speed_spell_clock(game);
	}
}

void activate_spell(game_global_t *game, int spell)
{
	player_info_t *player = game->player;
	int spell_cds[4] = {5, 2, 5, 5};
	spell_t spells[5] = {spell_speed, simple_, double_, circular_, NULL};

	if (player->spell_cd[spell] <= 0) {
		if (spell >= 2 && game->tree->attack_level < spell)
			player->spell_cd[spell] = 0;
		else
			player->spell_cd[spell] = spell_cds[spell];
		spells[spell](game);
	}
}