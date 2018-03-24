/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include "inventory.h"

int main(void)
{
	struct inventory_list_t	*list = create_inventory();

	add_inventory(list, "./fauxpath", "pomme");
	add_inventory(list, "./fauxpath", "poire");
	add_inventory(list, "./fauxpath", "pomme");
	add_inventory(list, "./fauxpath", "ananas");
	add_inventory(list, "./fauxpath", "pomme");
	del_inventory(list, "pomme");
	del_inventory(list, "pomme");
	del_inventory(list, "pomme");
	print_inventory(list);
}