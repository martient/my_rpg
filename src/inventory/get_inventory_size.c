/*
** EPITECH PROJECT, 2018
** get_inventory_size.c
** File description:
** Function that returns the number of objects it founds in the current inventory
*/

#include "my_rpg.h"

int get_inventory_size(inventory_list_t *ivnt)
{
	inventory_t *count = malloc(sizeof(inventory));
	int size = 0;

	if (ivnt == NULL)
		return (-1);
	count = ivnt->first;
	while (count != NULL) {
		size = size + count->quantity;
		count = count->next;
	}
	free(count);
	return (size);
}
