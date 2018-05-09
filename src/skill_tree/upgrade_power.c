/*
** EPITECH PROJECT, 2018
** upgrade_power.c
** File description:
** Function that upgrade your power in the skill tree
*/

#include "my_rpg.h"

int upgrade_power(struct game_global_t *game)
{
	int upgrade = POWER_UPGRADE_COST;

	if (game->tree->power_level == 5)
		return (-1);
	if (game->player->skill_point < upgrade)
		return (-1);
	game->tree->power_level = game->tree->power_level + 1;
	game->player->skill_point = game->player->skill_point - upgrade;
	if (game->tree->power_level == 2)
		game->player->power = SECOND_POWER;
	if (game->tree->power_level == 3)
		game->player->power = THIRD_POWER;
	if (game->tree->power_level == 4)
		game->player->power = FOURTH_POWER;
	if (game->tree->power_level == 5)
		game->player->power = FIFTH_POWER;
	return (0);
}