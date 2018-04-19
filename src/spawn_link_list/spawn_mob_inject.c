/*
** EPITECH PROJECT, 2018
** spawn_mob_inject.c
** File description:
** Epitech project
*/

#include "my_rpg.h"

int rpg_spawn_inject(spawn_first_t *first, int *data)
{
	spawn_mob_t *new = malloc(sizeof(spawn_mob_t));

	if (!first || !new) {
		my_putstr("Error: malloc doesn't sucesfull\n");
		return (-1);
	}
	new->id = first->first->id + 1;
	new->y = data[0];
	new->x = data[1];
	new->type = data[2];
	new->rate = data[3];
	new->next = first->first;
	first->first = new;
	return (0);
}
