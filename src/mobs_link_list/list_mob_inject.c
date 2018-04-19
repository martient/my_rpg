/*
** EPITECH PROJECT, 2018
** spawn_mob_inject.c
** File description:
** Epitech project
*/

#include "my_rpg.h"

static int rpg_mobs_inject(mob_first_t *first, mob_data_first_t *data,
	spawn_mob_t *spawn)
{
	mob_info_t *new = malloc(sizeof(mob_info_t));
	mob_data_t *data_tmp = NULL;

	if (!first || !new) {
		my_putstr("Error: malloc doesn't sucesfull\n");
		return (-1);
	}
	new->id = first->first->id + 1;
	new->y = spawn->x;
	new->x = spawn->y;
	while (data_tmp->next != NULL) {
		if (data_tmp->id == spawn->type) {
			new->type = spawn->type;
			break;
		}
		data_tmp->next = data_tmp->next->next;
	}
	new->agressive = 0;
	new->sprite = data_tmp->sprite;
	new->next = first->first;
	first->first = new;
	return (0);
}

int rpg_mob_generator(spawn_first_t *spawn, mob_data_first_t *data,
	mob_first_t *mobs, player_info_t *player)
{
	spawn_mob_t *spawn_tmp = NULL;

	if (!spawn || !data || !mobs || !player) {
		my_putstr("Error: one value gift is NULL\n");
		return (-1);
	}
	spawn_tmp = spawn->first;
	my_putstr("== start ==\n");
	while (spawn_tmp->next != NULL) {
		my_putstr("SHEAR\n");
		if ((player->x >= spawn_tmp->x - 10 && player->x <= spawn_tmp->x + 10) && (player->y >= spawn_tmp->y - 10 && player->y <= spawn_tmp->y + 10)) {
			rpg_mobs_inject(mobs, data, spawn_tmp);
			my_putstr("MOBS SPAWN\n");
			break;
		}
		spawn_tmp->next = spawn_tmp->next->next;
	}
	my_putstr("== end ==\n");
	return (0);
}
