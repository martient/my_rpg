/*
** EPITECH PROJECT, 2018
** spawn_mob_inject.c
** File description:
** Epitech project
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "my_rpg.h"

static mob_data_t *rpg_mobs_inject_shear(mob_info_t *new, mob_data_t *data_tmp,
spawn_mob_t *spawn)
{
	while (data_tmp->next != NULL) {
		if (data_tmp->id == spawn->type) {
			new->type = spawn->type;
			new->spawn = spawn;
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
		my_putstr("Error: malloc failed\n");
		return (-1);
	}
	new->id = first->first->id + 1;
	new->y = (float)spawn->y * 32 - (rand() % (spawn->size * 2));
	new->x = (float)spawn->x * 32 - (rand() % (spawn->size * 2));
	data_tmp = data->first;
	data_tmp = rpg_mobs_inject_shear(new, data_tmp, spawn);
	new->agressive = 0;
	new->sprite = data_tmp->sprite;
	new->health = 100.0;
	new->next = first->first;
	first->first = new;
	return (0);
}

int rpg_mob_generator(spawn_first_t *spawn, mob_data_first_t *data,
mob_first_t *mobs, player_info_t *player)
{
	spawn_mob_t *spawn_tmp = NULL;
	int mob_rand = 0;

	if (!spawn || !data || !mobs || !player) {
		my_putstr("Error: one value gift is NULL\n");
		return (-1);
	}
	spawn_tmp = spawn->first;
	while (spawn_tmp->next != NULL) {
		srand(time(NULL));
		mob_rand = (rand() % (RATE_SPAWN_MAX - RATE_SPAWN_MIN + 1))
		+ RATE_SPAWN_MIN;
		if (spawn_tmp->rate >= mob_rand) {
			rpg_mobs_inject(mobs, data, spawn_tmp);
		}
		spawn_tmp = spawn_tmp->next;
	}
	return (0);
}

int rpg_mob_generator_timer(game_global_t *game)
{
	double sec = sfTime_asSeconds(sfClock_getElapsedTime(game->clock));
	static double timer = 0;

	if (!game || timer > 0) {
		timer -= sec;
		return (-1);
	}
	rpg_mob_generator(game->mob_spawn, game->mob_data, game->mob_deploy,
	game->player);
	timer = 7;
	return (0);
}
