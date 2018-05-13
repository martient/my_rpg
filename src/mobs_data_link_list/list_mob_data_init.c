/*
** EPITECH PROJECT, 2018
** spawn_mob_init.c
** File description:
** Epitech project
*/

#include "my_rpg.h"

mob_data_first_t *rpg_mob_data_init(void)
{
	mob_data_first_t *first = malloc(sizeof(mob_data_first_t));
	mob_data_t *new = malloc(sizeof(mob_data_t));

	if (!first || !new) {
		my_putstr("Error: malloc doesn't sucesfull\n");
		return (NULL);
	}
	new->id = -1;
	new->name = NULL;
	new->attack_base = 0.0;
	new->attack_grow = 0.0;
	new->healt_base = 0.0;
	new->healt_grow = 0.0;
	new->armor_base = 0.0;
	new->armor_grow = 0.0;
	new->speed = 0.0;
	new->next = NULL;
	first->first = new;
	return (first);
}
