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

	inventory_new_obj(list, "Golden Apple");
	inventory_new_obj(list, "Golden Apple");
	inventory_new_obj(list, "Golden Apple");
	inventory_new_obj(list, "Golden Apple");
	inventory_new_obj(list, "Golden Apple");
	inventory_new_obj(list, "Golden Apple");
	inventory_new_obj(list, "Golden Apple");
	inventory_new_obj(list, "Golden Apple");
	inventory_new_obj(list, "Golden Apple");
	inventory_new_obj(list, "Golden Apple");
	inventory_new_obj(list, "Golden Apple");
	inventory_new_obj(list, "Golden Apple");
	inventory_new_obj(list, "Golden Apple");
	inventory_new_obj(list, "Golden Apple");
	inventory_new_obj(list, "Golden Apple");
	inventory_new_obj(list, "Golden Apple");
	inventory_new_obj(list, "Golden Apple");
	inventory_new_obj(list, "Golden Apple");
	inventory_new_obj(list, "Golden Apple");
	inventory_new_obj(list, "Golden Apple");
	inventory_new_obj(list, "Golden Apple");
	print_inventory(list);
}