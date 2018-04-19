/*
** EPITECH PROJECT, 2018
** spawn_mob_init.c
** File description:
** Epitech project
*/

#include "my_rpg.h"

spawn_first_t *rpg_spawn_init(void)
{
	spawn_first_t *first = malloc(sizeof(spawn_first_t));
	spawn_mob_t *new = malloc(sizeof(spawn_mob_t));

	if (!first || !new) {
		my_putstr("Error: malloc doesn't sucesfull\n");
		exit(84);
	}
	new->id = 0;
	new->y = 0;
	new->x = 0;
	new->type = 0;
	new->rate = 0;
	new->size= 0;
	new->next = NULL;
	first->first = new;
	return (first);
}
