/*
** EPITECH PROJECT, 2018
** reset_inventory.c
** File description:
** Function that reset the inventory
*/

#include "global.h"
#include "inventory.h"

int reset_inventory(inventory_list_t *ivnt)
{
	inventory_t *count = ivnt->first;

	if (ivnt == NULL)
		return (-1);
	while (count != NULL) {
		count->quantity = 0;
		count->name = NULL;
		count = count->next;
	}
	free(count);
	return (0);
}