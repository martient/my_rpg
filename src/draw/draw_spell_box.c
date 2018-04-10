/*
** EPITECH PROJECT, 2018
** draw_spell_cd.c
** File description:
** draw spell box with cooldown
*/

#include "my_rpg.h"

int draw_spell_cd_box(game_global_t *game, double percentage)
{
	int info[5];
	sfColor colors[2] = {sfBlue, sfRed};

	info[0] = 40;
	info[1] = 40;
	info[4] = game->player->y + (game->height / 2) - 70;
	for (int i = 0; i < 4; i++) {
		info[2] = (game->player->spell_cd[i] * 100) / 5;
		info[3] = (game->player->x - 150) + (i * 86);
		draw_bar(game, colors, info);
	}
	return (0);
}