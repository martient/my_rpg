/*
** EPITECH PROJECT, 2018
** spell_1_speed.c
** File description:
** function for spell 1 speed
*/

#include "my_rpg.h"

int spell_speed(game_global_t *game)
{
	player_info_t *player = game->player;

	if (player->spell_duration[0] == 0) {
		player->speed = 1.25;
		player->spell_duration[0] = 5;
	}
	return (0);
}

int speed_spell_clock(game_global_t *game)
{
	player_info_t *player = game->player;

	if (player->spell_duration[0] == 0)
		player->speed = 1;
	return (0);
}