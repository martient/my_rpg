/*
** EPITECH PROJECT, 2018
** spawn_init.c
** File description:
** Epitech project
*/

#include "my_rpg.h"

int rpg_mob_data_init_list(mob_data_first_t *first)
{
	if (!first) {
		my_putstr("Error: malloc doesn't sucesfull\n");
		return (-1);
	}
	rpg_json_init_mob_data(first);
	return (0);
}
