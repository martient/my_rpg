/*
** EPITECH PROJECT, 2018
** rpg_map_cycle.c
** File description:
** MODIFIER
*/

#include "my_rpg.h"

int rpg_init_global_info(object_first_t *info)
{
	if (!info) {
		my_putstr("Error: value gift is null\n");
		return (0);
	}
	rpg_inject_object_grass_list(info);
	return (1);
}
