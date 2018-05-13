/*
** EPITECH PROJECT, 2018
** double_attack.c
** File description:
** Function that manage the double attack
*/

#include "my_rpg.h"

int double_(game_global_t *game)
{
	if (game->tree->attack_level < 2)
		return (-1);
	play_sound(game, "d_sword");
	if (find_mob(2, game) == 1)
		return (1);
	return (0);
}