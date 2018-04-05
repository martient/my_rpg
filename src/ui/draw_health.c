/*
** EPITECH PROJECT, 2018
** draw_health.c
** File description:
** draw player health bar
*/

#include "my_rpg.h"

int draw_health(game_global_t *game)
{
	player_info_t *player = game->player;

	int health_perc = (player->health * 100) / player->max_health;
	int info[5] = {300, 20, health_perc, game->player->x - 150, game->player->y + (game->height / 2) - 20};
	sfColor colors[2] = {sfRed, sfGreen};
	draw_bar(game, colors, info);
	return (0);
}