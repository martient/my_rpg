/*
** EPITECH PROJECT, 2018
** init_all_items_data_link_list.c
** File description:
** Epitech project
*/

#include "my_rpg.h"

int rpg_init_link_list_items_data(items_data_first_t *first)
{
	if (!first) {
		my_putstr("Error: malloc\n");
		return (-1);
	}
	rpg_json_init_items_data(first);
	return (0);

}
