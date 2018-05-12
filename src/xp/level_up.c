/*
** EPITECH PROJECT, 2018
** level_up.c
** File description:
** Function that makes you go level up
*/

#include "my_rpg.h"

void level_up(game_global_t *game)
{
	while (game->player->xp >= 500) {
		game->player->level = game->player->level + 1;
		game->player->xp = game->player->xp - 500;
		game->player->skill_point = game->player->skill_point + 2;
	}
}