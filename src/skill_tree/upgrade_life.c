/*
** EPITECH PROJECT, 2018
** upgrade_life.c
** File description:
** Function that upgrade your life max in the skill tree
*/

#include "my_rpg.h"

int upgrade_life(struct game_global_t *game)
{
	int upgrade = LIFE_UPGRADE_COST_H_;

	if (game->tree->life_level == 5)
		return (-1);
	if (game->player->skill_point < upgrade)
		return (-1);
	game->tree->life_level = game->tree->life_level + 1;
	game->player->skill_point = game->player->skill_point - upgrade;
	return (0);
}