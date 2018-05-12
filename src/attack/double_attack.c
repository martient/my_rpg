/*
** EPITECH PROJECT, 2018
** double_attack.c
** File description:
** Function that manage the double attack
*/

#include "global.h"

int find_mob(int opt, game_global_t *game);

int double_(game_global_t *game)
{
	play_sound(game, "d_sword");
	if (find_mob(2, game) == 1)
		return (1);
	return (0);
}