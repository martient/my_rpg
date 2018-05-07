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

	if (diff_x > -48 && diff_x < 35) {
		if (diff_y > -48 && diff_y < 35) {
			mob->health = mob->health - CIRCULAR_ATTACK;
			printf("Circular");
		}
	}
}

int all_touched(mob_info_t *mob, player_info_t *player)
{
	int health = 0;
	int value = 0;

	while (mob->next != NULL) {
		health = mob->health;
		analyse_circle(mob, player);
		if (health != mob->health)
			value = 1;
		mob = mob->next;
	}
	printf("%f\n", mob->health);
	return (value);
}

int circular_attack(game_global_t *game)
{
	if (find_mob(2, game) == 1)
		return (1);
	return (0);
}