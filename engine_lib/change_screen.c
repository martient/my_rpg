/*
** EPITECH PROJECT, 2018
** change_screen.c
** File description:
** function to change screen
*/

#include "engine.h"

void engine_change_screen_by_id(game_global_t *global, int id)
{
	global->screen_id = id;
}