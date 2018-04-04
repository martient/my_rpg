/*
** EPITECH PROJECT, 2018
** screen_event.c
** File description:
** function for screen related events
*/

#include "my_rpg.h"

void update_screen_size(game_global_t *game)
{
	sfVector2u screen_size;

	screen_size = sfRenderWindow_getSize(game->window);
	game->width = screen_size.x;
	game->height = screen_size.y;
}