/*
** EPITECH PROJECT, 2018
** draw_player.c
** File description:
** function to draw player with its camera
*/

#include "my_rpg.h"

void draw_player(game_global_t *game)
{
	player_info_t *player = game->player;
	sfVector2f center = {player->x, player->y};
	sfFloatRect cam = {0, 0, game->width, game->height};

	player->camera = sfView_createFromRect(cam);
	sfView_setCenter(player->camera, center);
	sfRenderWindow_setView(game->window, player->camera);
}