/*
** EPITECH PROJECT, 2018
** draw_hub.c
** File description:
** main 
*/

#include "my_rpg.h"

void draw__(game_global_t *game)
{
	printf("X:%f; Y:%f\n", game->player->x, game->player->y);
	sfRenderWindow_clear(game->window, sfWhite);
	draw_player(game);
	sfRenderWindow_display(game->window);	
}