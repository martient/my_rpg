/*
** EPITECH PROJECT, 2018
** game_event.c
** File description:
** function for handling game events
*/

#include "my_rpg.h"

void engine_exit(game_global_t *global)
{
	sfRenderWindow_close(global->window);
	global->screen_id = -1;
}