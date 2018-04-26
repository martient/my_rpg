/*
** EPITECH PROJECT, 2018
** items_data_init.c
** File description:
** Epitech project
*/

#include "my_rpg.h"

items_data_first_t *rpg_items_data_init(void)
{
	items_data_first_t *first = malloc(sizeof(items_data_first_t));
	items_data_t *new = malloc(sizeof(items_data_t));

	if (!first || !new) {
		my_putstr("Error: Malloc\n");
		return (NULL);
	}
	new->id = -1;
	new->name = NULL;
	new->type = -1;
	new->stats = -1;
	new->texture = NULL;
	new->sprite = NULL;
	new->next = NULL;
	first->first = new;
	return (first);
}
