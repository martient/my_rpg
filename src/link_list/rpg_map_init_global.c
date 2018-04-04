/*
** EPITECH PROJECT, 2018
** rpg_map_cycle.c
** File description:
** MODIFIER
*/

#include "my_rpg.h"

int rpg_init_global_info(object_first_t *info)
{
	if (rpg_inject_object_grass_list(info) == -1)
		return (0);
	return (1);
}
