/*
** EPITECH PROJECT, 2018
** spawn_mob_init.c
** File description:
** Epitech project
*/

#include "my_rpg.h"

mob_first_t *rpg_mob_init(void)
{
	mob_first_t *first = malloc(sizeof(mob_info_t));
	mob_info_t *new = malloc(sizeof(mob_info_t));

	if (!first || !new) {
		my_putstr("Error: malloc doesn't sucesfull\n");
		return (NULL);
	}
	new->id = -1;
	new->y = 0;
	new->x = 0;
	new->type = 0;
	new->agressive = 0;
	new->level = 0;
	new->next = NULL;
	new->spawn = NULL;
	first->first = new;
	return (first);
}
