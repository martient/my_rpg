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
	int info[5] = {300, 350, 100, player->x + 100, player->y - (game->height / 2) + 150};
	int text_info[3] = {player->x + 170, player->y - (game->height / 2) + 150, 32};
	sfColor colors[2] = {sfRed, sfBrown};

	if (game->inventory_show == 0)
		return (1);
	draw_bar(game, colors, info);
	engine_create_text(game, INVENTORY, text_info, sfWhite);
	return (0);
}