/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include "inventory.h"

int main(void)
{
	struct inventory_list_t	*list = init_inventory();

	inventory_new_obj(list, "Apple");
	inventory_new_obj(list, "Apple");
	inventory_new_obj(list, "Apple");
	inventory_new_obj(list, "Apple");
	inventory_new_obj(list, "Apple");
	inventory_new_obj(list, "Apple");
	inventory_new_obj(list, "Pineapple");
	inventory_new_obj(list, "Avocado");
	inventory_new_obj(list, "Pineapple");
	inventory_new_obj(list, "Avocado");
	inventory_new_obj(list, "Pineapple");
	inventory_new_obj(list, "Avocado");
	print_inventory(list);
}