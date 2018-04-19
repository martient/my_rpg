/*
** EPITECH PROJECT, 2018
** spawn_init.c
** File description:
** Epitech project
*/

#include "my_rpg.h"

int rpg_spawn_init_list(spawn_first_t *first)
{
	if (!first) {
		my_putstr("Error: malloc doesn't sucesfull\n");
		return (-1);
	}
	rpg_json_init_spawn(first);
	return (0);
}
