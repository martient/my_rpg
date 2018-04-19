/*
** EPITECH PROJECT, 2018
** spawn_remove.c
** File description:
** Epitech project
*/

#include "my_rpg.h"

int rpg_mob_data_remove(mob_data_first_t *first)
{
	mob_data_t *remove = NULL;

	if (!first) {
		my_putstr("Error: value gift is NULL\n");
		return (-1);
	} else if (first->first != NULL) {
		remove = first->first;
		first->first = first->first->next;
		free(remove);
	}
	return (0);
}
