/*
** EPITECH PROJECT, 2018
** items_data_init.c
** File description:
** Epitech project
*/

#include "my_rpg.h"

static int rpg_items_data_init_tex(items_data_t *new)
{
	sfIntRect spritesheet_rect = {0, 0, 32, 32};
	char *tmp = "./resources/sprites/inventory/carrots.png";

	new->texture = sfTexture_createFromFile(tmp, NULL);
	new->sprite = sfSprite_create();
	sfSprite_setTexture(new->sprite, new->texture, sfTrue);
	sfSprite_setTextureRect(new->sprite, spritesheet_rect);
	return (0);
}

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
	new->x = 0;
	new->y = 0;
	new->stats = -1;
	rpg_items_data_init_tex(new);
	new->next = NULL;
	first->first = new;
	return (first);
}
