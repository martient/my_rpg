/*
** EPITECH PROJECT, 2018
** find_mob.c
** File description:
** Function that finds any mob on the map
*/

#include "my_rpg.h"

void analyse_mob(struct mob_info_t *mob, struct player_info_t *player)
{
	double diff_x = player->x - mob->x;
	double diff_y = player->y - mob->y;
	double init_life = mob->health;

	if (player->direction == 1) {
		if (diff_x > -20 && diff_x < 20 && diff_y > -48 && diff_y < 32)
			mob->health = mob->health - NORMAL_ATTACK;
	}
	if (player->direction == 2) {
		if (diff_x > -32 && diff_x < 32 && diff_y > -15 && diff_y < 15)
			mob->health = mob->health - NORMAL_ATTACK;
	}
	if (player->direction == 3) {
		if (diff_x > -32 && diff_x < 32 && diff_y > -15 && diff_y < 15)
			mob->health = mob->health - NORMAL_ATTACK;
	}
	if (player->direction == 4) {
		if (diff_x > -20 && diff_x < 20 && diff_y > -32 && diff_y < 32)
			mob->health = mob->health - NORMAL_ATTACK;
	}
}

int touched(mob_info_t *mob, player_info_t *player)
{
	int health = 0;

	while (mob->next != NULL) {
		health = mob->health;
		analyse_mob(mob, player);
		if (health != mob->health)
			return (1);
		mob = mob->next;
	}
	return (0);
}

int find_mob(int opt, game_global_t *game)
{
	mob_info_t *mob = game->mob_deploy->first;

	if (opt == 1) {
		if (touched(mob, game->player) == 1)
			return (1);
	}
	if (opt == 2) {
		if (all_touched(mob, game->player) == 1)
			return (1);
	}
	return (0);
}
