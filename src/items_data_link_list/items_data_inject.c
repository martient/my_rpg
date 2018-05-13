/*
** EPITECH PROJECT, 2018
** items_data_inject.c
** File description:
** Epitech project
*/

#include "my_rpg.h"

int rpg_items_data_inject(items_data_first_t *first, char **string, int *data,
float stats)
{
	sfIntRect spritesheet_rect = {0, 0, 32, 32};
	items_data_t *new = malloc(sizeof(items_data_t));

	if (!first || !new) {
		my_putstr("Error: malloc or gift value\n");
		return (-1);
	}
	new->id = data[0];
	new->name = string[0];
	new->type = data[1];
	new->stats = stats;
	new->texture = sfTexture_createFromFile(string[1], NULL);
	new->sprite = sfSprite_create();
	sfSprite_setTexture(new->sprite, new->texture, sfTrue);
	sfSprite_setTextureRect(new->sprite, spritesheet_rect);
	new->next = first->first;
	first->first = new;
	return (0);
}
