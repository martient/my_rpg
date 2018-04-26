/*
** EPITECH PROJECT, 2018
** print_inventory.c
** File description:
** Function that print the name and quantity of each element in the inventory
*/

#include "my_rpg.h"

int print_inventory(inventory_list *ivnt)
{
	inventory_t *current = malloc(sizeof(inventory_t));

	if (ivnt == NULL)
		return (-1);
	current = ivnt->first;
	while (current != NULL) {
		my_putstr(current->name);
		write(1, "\n", 1);
		my_put_nbr(current->quantity);
		write(1, "\n", 1);
		current = current->next;
	}
	free(current);
	return (0);
}
