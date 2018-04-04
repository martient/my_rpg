/*
** EPITECH PROJECT, 2018
** rpg_remove_object_list.c
** File description:
** MODIFIER
*/

#include "my_rpg.h"

int rpg_remove_object_list(object_first_t *info)
{
	object_info_t *remove = NULL;

	if (!info) {
		my_putstr("Error: malloc new struct\n");
		return (-1);
	} else if (info->first != NULL) {
		remove = info->first;
		info->first = info->first->next;
		free(remove);
	}
	return (0);
}
