/*
** EPITECH PROJECT, 2018
** spawn_remove.c
** File description:
** Epitech project
*/

#include "my_rpg.h"

static int rpg_mob_remove_previoux(mob_first_t *first, int id)
{
	mob_info_t *current = NULL;
	mob_info_t *previous = NULL;

	if (!first)
		return (84);
	current = first->first;
	while (current != NULL) {
		if (current->id == id && previous == NULL) {
			first->first = first->first->next;
			break;
		}
		if (current->id == id && previous != NULL) {
			previous->next = current->next;
			break;
		}
		previous = current;
		current = current->next;
	}
	return (0);
}

int rpg_mob_remove(mob_first_t *first)
{
	mob_info_t *remove = NULL;

	if (!first) {
		my_putstr("Error: value gift is NULL\n");
		return (-1);
	}
	while (first->first != NULL) {
		remove = first->first;
		first->first = first->first->next;
		free(remove);
	}
	free(first);
	return (0);
}

int rpg_mob_remove_spe(mob_first_t *first, mob_info_t *mobs)
{
	mob_info_t *remove = NULL;

	if (!mobs || !first) {
		my_putstr("Error: value gift is NULL\n");
		return (-1);
	} else {
		remove = mobs;
		rpg_mob_remove_previoux(first, remove->id);
		free(remove);
	}
	return (0);
}
