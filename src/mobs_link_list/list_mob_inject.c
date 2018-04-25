/*
** EPITECH PROJECT, 2018
** spawn_mob_inject.c
** File description:
** Epitech project
*/

#include "my_rpg.h"

static mob_data_t *rpg_mobs_inject_shear(mob_info_t *new, mob_data_t *data_tmp,
spawn_mob_t *spawn)
{
	while (data_tmp->next != NULL) {
		if (data_tmp->id == spawn->type) {
			new->type = spawn->type;
			break;
		}
		data_tmp->next = data_tmp->next->next;
	}
	return (data_tmp);
}

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
	new->y = spawn->y;
	new->x = spawn->x;
	data_tmp = data->first;
	data_tmp = rpg_mobs_inject_shear(new, data_tmp, spawn);
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
	while (spawn_tmp->next != NULL) {
		if (((int)player->x / 32 >= (int)spawn_tmp->x - 10 &&
		(int)player->x / 32 <= (int)spawn_tmp->x + 10) &&
		((int)player->y / 32 >= (int)spawn_tmp->y - 10 &&
		(int)player->y / 32 <= (int)spawn_tmp->y + 10)) {
			rpg_mobs_inject(mobs, data, spawn_tmp);
			break;
		}
		spawn_tmp = spawn_tmp->next;
	}
	return (0);
}
