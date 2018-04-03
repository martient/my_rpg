/*
** EPITECH PROJECT, 2018
** rpg_map_cycle.c
** File description:
** MODIFIER
*/

#include "my_rpg.h"

int rpg_init_global_info(object_first_t *info)
{
	info = rpg_init_object_list();
	rpg_json_map_init(info);
	rpg_display_name_object_list(info);
	rpg_remove_object_list(info);
	return (0);
}
