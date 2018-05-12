/*
** EPITECH PROJECT, 2018
** items_data_search.c
** File description:
** Epitech project
*/

#include "my_rpg.h"

items_data_t *inventory_get_items(items_data_first_t *info,
char *target)
{
	items_data_t *display = NULL;

	if (!info || !target) {
		my_putstr("Error: malloc new struct (inv get)\n");
		return (NULL);
	}
	display = info->first;
	while (display != NULL) {
		if (my_strcmp(display->name, target) == 0) {
			return (display);
			break;
		}
		display = display->next;
	}
	return (NULL);
}
