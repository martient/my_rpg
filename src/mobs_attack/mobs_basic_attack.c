/*
** EPITECH PROJECT, 2018
** mobs_basic_attack.c
** File description:
** Function that makes the basic mobs attack you
*/

#include "my_rpg.h"

void touch_player(mob_info_t *mob, player_info_t *player)
{
	double diff_x = mob->x - player->x;
	double diff_y = mob->y - player->y;

	if (diff_x > -32 && diff_x < 32) {
		if (diff_y > -32 && diff_y < 32) {
			player->health = player->health - MOBS_SIMPLE_ATTACK;
		}
	}
}

void attack_player(mob_first_t *first, player_info_t *player)
{
	mob_info_t *mob = first->first;

	while (mob->next != NULL) {
		touch_player(mob, player);
		mob = mob->next;
	}
}

void mobs_basic_attack(game_global_t *game)
{
	mob_first_t *first = game->mob_deploy;

	attack_player(first, game->player);
}