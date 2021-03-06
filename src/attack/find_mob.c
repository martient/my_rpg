/*
** EPITECH PROJECT, 2018
** find_mob.c
** File description:
** Function that finds any mob on the map
*/

#include "my_rpg.h"

void analyse_mob(int t, mob_info_t *mob, player_info_t *player)
{
	double diff_x = player->x - mob->x;
	double diff_y = player->y - mob->y;
	float pwr = player->power;

	if (player->direction == 1) {
		if (diff_x > -32 && diff_x < 32 && diff_y > -48 && diff_y < 32)
			mob->health = mob->health - (NORMAL_ATTACK * t * pwr);
	}
	if (player->direction == 2) {
		if (diff_x > -32 && diff_x < 32 && diff_y > -32 && diff_y < 32)
			mob->health = mob->health - (NORMAL_ATTACK * t * pwr);
	}
	if (player->direction == 3) {
		if (diff_x > -32 && diff_x < 32 && diff_y > -32 && diff_y < 32)
			mob->health = mob->health - (NORMAL_ATTACK * t * pwr);
	}
	if (player->direction == 4) {
		if (diff_x > -32 && diff_x < 32 && diff_y > -32 && diff_y < 32)
			mob->health = mob->health - (NORMAL_ATTACK * t * pwr);
	}
}

int touched(int type, mob_first_t *first, player_info_t *player)
{
	int health = 0;
	int value = 0;
	mob_info_t *mob = first->first;

	while (mob->next != NULL) {
		health = mob->health;
		analyse_mob(type, mob, player);
		if (health != mob->health)
			value = 1;
		if (mob->health <= 0) {
			rpg_mob_remove_spe(first, mob);
			fallen_killed_monster(player, 1);
			player->xp = player->xp + 50;
		}
		mob = mob->next;
	}
	return (value);
}

int find_mob(int opt, game_global_t *game)
{
	mob_first_t *mob = game->mob_deploy;

	if (opt == 1) {
		if (touched(1, mob, game->player) == 1)
			return (1);
	}
	if (opt == 2) {
		if (touched(2, mob, game->player) == 1)
			return (1);
	}
	if (opt == 3) {
		if (all_touched(mob, game->player) == 1)
			return (1);
	}
	return (0);
}
