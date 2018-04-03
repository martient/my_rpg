/*
** EPITECH PROJECT, 2018
** init_inventory.c
** File description:
** Function that initialize the inventory
*/

#include "inventory.h"

inventory_list *init_inventory(void)
{
	struct inventory_list *invent = malloc(sizeof(inventory_list));
	struct inventory *element = malloc(sizeof(inventory));

	if (invent == NULL || element == NULL)
		return (NULL);
	element->text = NULL;
	element->spr = NULL;
	element->name = NULL;
	element->desc = NULL;
	element->quantity = 0;
	element->id = 0;
	element->next = NULL;
	invent->first = element;
	return (invent);
}