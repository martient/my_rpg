/*
** EPITECH PROJECT, 2018
** double_attack.c
** File description:
** Function that manage the double attack
*/

#include "global.h"
#include "my_rpg.h"

int double_attack(game_global_t *game)
{
	if (find_mob(2, game) == 1)
		return (1);
	return (0);
}