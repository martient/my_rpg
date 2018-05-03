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

	if (player->direction == 1) {
		if (diff_x > -10 && diff_x < 10 && diff_y > -32 && diff_y < 0) {
			mob->health = mob->health - NORMAL_ATTACK;
			printf("down %g\n", mob->health);
		}
	}
	if (player->direction == 2) {
		if (diff_x > -1 && diff_x < 32 && diff_y > -10 && diff_y < 10) {
			mob->health = mob->health - NORMAL_ATTACK;
			printf("left %g\n", mob->health);
		}
	}
	if (player->direction == 3) {
		if (diff_x > -32 && diff_x < 1 && diff_y > -10 && diff_y < 10) {
			mob->health = mob->health - NORMAL_ATTACK;
			printf("right %g\n", mob->health);
		}
	}
	if (player->direction == 4) {
		if (diff_x > -10 && diff_x < 10 && diff_y > 0 && diff_y < 32) {
			mob->health = mob->health - NORMAL_ATTACK;
			printf("up %g\n", mob->health);
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
