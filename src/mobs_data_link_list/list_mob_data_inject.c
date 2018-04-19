/*
** EPITECH PROJECT, 2018
** spawn_mob_inject.c
** File description:
** Epitech project
*/

#include "my_rpg.h"

int rpg_mob_data_inject(mob_data_first_t *first, float *data, int id,
	char* name)
{
	mob_data_t *new = malloc(sizeof(mob_data_t));

	if (!first || !new || !data || !name) {
		my_putstr("Error: malloc doesn't sucesfull\n");
		return (-1);
	}
	new->id = first->first->id + 1;
	new->name = name;
	new->attack_base = data[0];
	new->attack_grow = data[1];
	new->healt_base = data[2];
	new->healt_grow = data[3];
	new->armor_base = data[4];
	new->armor_grow = data[5];
	new->speed = data[6];
	new->next = first->first;
	first->first = new;
	return (0);
}

int rpg_mob_data_tex_inject(mob_data_first_t *first, char *pathfile)
{
	mob_data_t *tmp;
	sfIntRect spritesheet_rect = {0, 0, 32, 32};

	if (!first) {
		my_putstr("Error: Value gift not found\n");
		return (-1);
	}
	tmp = first->first;
	tmp->texture = sfTexture_createFromFile(pathfile, NULL);
	tmp->sprite = sfSprite_create();
	sfSprite_setTexture(tmp->sprite, tmp->texture, sfTrue);
	sfSprite_setTextureRect(tmp->sprite, spritesheet_rect);
	return (0);
}
