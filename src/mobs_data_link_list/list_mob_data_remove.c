/*
** EPITECH PROJECT, 2018
** spawn_remove.c
** File description:
** Epitech project
*/

#include "my_rpg.h"

static int rpg_mob_data_remove(mob_data_first_t *first)
{
	mob_data_t *remove = NULL;

	if (!first)
		return (-1);
	else if (first->first != NULL || !remove->sprite) {
		remove = first->first;
		first->first = first->first->next;
		free(remove->name);
		free(remove);
	}
	return (0);
}

int rpg_mob_data_remove_all(mob_data_first_t *first)
{
	if (!first)
		return (-1);
	while (first->first != NULL) {
		rpg_mob_data_remove(first);
	}
	free(first);
	return (0);
}
