/*
** EPITECH PROJECT, 2018
** upgrade_attack.c
** File description:
** Function that upgrade the attacks in the skill tree
*/

#include "my_rpg.h"

int upgrade_knight_attacks(struct game_global_t *game)
{
	int up = CIRCULAR_ATTACK_COST_H_;
	int up2 = HAMMER_JUSTICE_COST_H_;

	if (game->tree->attack_level == 1) {
		if (game->player->skill_point < up)
			return (-1);
		game->player->skill_point = game->player->skill_point - up;
		game->tree->attack_level = game->tree->attack_level + 1;
		return (0);
	}
	if (game->tree->attack_level == 2) {
		if (game->player->skill_point < up2)
			return (-1);
		game->player->skill_point = game->player->skill_point - up2;
		game->tree->attack_level = game->tree->attack_level + 1;
		return (0);
	}
	return (-1);
}