/*
** EPITECH PROJECT, 2018
** set_items_position.c
** File description:
** Epitech project
*/

#include "my_rpg.h"

int inventory_set_items(items_data_t *info, int x, int y)
{
	if (!info) {
		my_putstr("Error: with value gift !\n");
		return (-1);
	}
	info->x = x;
	info->y = y;
	return (0);
}
