/*
** EPITECH PROJECT, 2018
** init_inventory.c
** File description:
** Function that initialize the inventory
*/

#include "global.h"
#include "inventory.h"
#include "lib.h"

inventory_list_t *init_inventory(void)
{
	inventory_list_t *invent = malloc(sizeof(inventory_list_t));
	inventory_t *element = malloc(sizeof(inventory_t));

	if (invent == NULL || element == NULL)
		return (NULL);
	element->text = NULL;
	element->spr = NULL;
	element->name = "item_secret_defence";
	element->desc = NULL;
	element->quantity = -1;
	element->id = -1;
	element->x = 0;
	element->y = 0;
	element->next = NULL;
	invent->first = element;
	return (invent);
}
