/*
** EPITECH PROJECT, 2018
** circular_attack.c
** File description:
** Function that calls the circular attack
*/

#include "my_rpg.h"

void analyse_circle(mob_info_t *mob, player_info_t *player)
{
	double diff_x = player->x - mob->x;
	double diff_y = player->y - mob->y;
	float pw = player->power;

	if (diff_x > -48 && diff_x < 48) {
		if (diff_y > -48 && diff_y < 48) {
			mob->health = mob->health - (CIRCULAR_ATTACK * pw);
		}
	}
}

int all_touched(mob_first_t *first, player_info_t *player)
{
	int health = 0;
	int value = 0;
	mob_info_t *mob = first->first;

	while (mob->next != NULL) {
		health = mob->health;
		analyse_circle(mob, player);
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

int circular_(game_global_t *game)
{
	if (game->tree->attack_level < 3)
		return (-1);
	play_sound(game, "sword");
	if (find_mob(3, game) == 1)
		return (1);
	return (0);
}