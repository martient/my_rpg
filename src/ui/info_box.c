/*
** EPITECH PROJECT, 2018
** info_box.c
** File description:
** function to draw info_box
*/

#include "my_rpg.h"

static int generate_box(game_global_t *game, char *text)
{
	int info[3] = {game->player->x - 150, game->player->y + (game->height / 2) - 100, 32};
	engine_create_text(game, text, info, sfBlack);
	return (0);
}

int draw_box(game_global_t *game, char *text, int kill)
{
	static int box_alive = 0;

	if (kill == 1)
		box_alive = 0;
	if (kill == 0)
		box_alive = 1;
	if (box_alive == 1) {
		generate_box(game, text);
		return (1);
	}
	return (0);
}