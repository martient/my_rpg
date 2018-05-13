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

int attack_player(mob_first_t *first, player_info_t *player)
{
	mob_info_t *mob = first->first;

	while (mob->next != NULL) {
		touch_player(mob, player);
		if (player->health <= 0)
			return (1);
		mob = mob->next;
	}
	return (0);
}

void mobs_basic_attack(game_global_t *game)
{
	mob_first_t *first = game->mob_deploy;

	if (attack_player(first, game->player) == 1) {
		game->player->x = 86;
		game->player->y = 3113;
		game->player->health = game->player->max_health;
		game->player->xp = 0;
		reset_inventory(game->invent);
	}
}