/*
** EPITECH PROJECT, 2018
** draw_inventory.h
** File description:
** function to draw inventory
*/

#include "my_rpg.h"

int draw_inventory(game_global_t *game)
{
	player_info_t *player = game->player;
	sfColor sfBrown = {182, 155, 76, 255};

	if (game->inventory_show == 0)
		return (1);
	int info[5] = {300, 350, 100, player->x + 100, player->y - (game->height / 2) + 150};
	sfColor colors[2] = {sfRed, sfBrown};
	draw_bar(game, colors, info);
	return (0);
}