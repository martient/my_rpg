/*
** EPITECH PROJECT, 2018
** rpg_debug_display_object_list.c
** File description:
** MODIFIER
*/

#include "my_rpg.h"

int rpg_display_name_object_list(object_first_t *info)
{
	object_info_t *display = NULL;

	if (!info) {
		my_putstr("Error: malloc new struct\n");
		return (-1);
	}
	display = info->first;
	while (display != NULL && display->name != NULL) {
		my_putstr(" -> ");
		my_putstr(display->name);
		display = display->next;
	}
	return (0);
}
