/*
** EPITECH PROJECT, 2018
** find_mob.c
** File description:
** Function that finds any mob on the map
*/

#include "my_rpg.h"

void analyse_mob(struct mob_info_t *mob, struct player_info_t *player)
{
	int real_x = mob->x / 32;
	int real_y = mob->y / 32;
	int real_x2 = player->x / 32;
	int real_y2 = player->y / 32;

	if (player->direction == 1) {
		if (real_x == real_x2 && real_y == real_y2 + 1) {
			mob->health = mob->health - NORMAL_ATTACK;
			printf("%g\n", mob->health);
		}
	}
	if (player->direction == 2) {
		if (real_x == real_x2 - 1 && real_y == real_y2) {
			mob->health = mob->health - NORMAL_ATTACK;
			printf("%g\n", mob->health);
		}
	}
	if (player->direction == 3) {
		if (real_x == real_x2 && real_y == real_y2 - 1) {
			mob->health = mob->health - NORMAL_ATTACK;
			printf("%g\n", mob->health);
		}
	}
	if (player->direction == 4) {
		if (real_x == real_x2 + 1 && real_y == real_y2) {
			mob->health = mob->health - NORMAL_ATTACK;
			printf("%g\n", mob->health);
		}
	}
}

int find_mob(int opt, game_global_t *game)
{
	mob_info_t *mob = game->mob_deploy->first;

	if (opt == 1) {
		while (mob->next != NULL) {
			analyse_mob(mob, game->player);
			mob = mob->next;
		}
	}
	return (0);
}
