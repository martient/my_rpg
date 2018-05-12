/*
** EPITECH PROJECT, 2018
** simple_attack.c
** File description:
** Function that makes a simple attack
*/

#include "global.h"

int find_mob(int opt, game_global_t *game);

int simple_(struct game_global_t *game)
{
	play_sound(game, "sword");
	if (find_mob(1, game) == 1) {
		return (1);
	}
	return (0);
}