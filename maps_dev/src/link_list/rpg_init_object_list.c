/*
** EPITECH PROJECT, 2018
** rpg_init_object_list.c
** File description:
** MODIFIER
*/

#include <stdio.h>
#include "my_rpg.h"

object_first_t *rpg_init_object_list(void)
{
	object_first_t *first = malloc(sizeof(object_first_t) * 2);
	object_info_t *new = malloc(sizeof(object_info_t) * 2);

	if (!first || !new) {
		my_putstr("Error: malloc new struct\n");
		return (NULL);
	}
	new->name = NULL;
	new->x = 0;
	new->y = 0;
	new->z = 0;
	new->collider = 0;
	new->type = 0;
	new->visible = 0;
	new->texture = NULL;
	new->sprite = NULL;
	new->next = NULL;
	first->first = new;
	return first;
}
