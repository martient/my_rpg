/*
** EPITECH PROJECT, 2018
** mob_mouvement.c
** File description:
** function to move mob
*/

#include "my_rpg.h"

static int can_move(float x, float y, int box_x, int box_y, long size)
{
	if (x >= box_x + size ||
	x <= box_x ||
	y >= box_y + size ||
	y <= box_y) {
		return (1);
	}
	return (0);
}

int next_move(void)
{
	int coef = rand() % 1000;

	if (coef % 2)
		return (-1);
	return (1);
}

//Passive
int mob_move_passive(mob_info_t *mob, double delta_time)
{
	float x = mob->x;
	float y = mob->y;
	int move = rand() % 100;
	int coef = next_move();
	long size = mob->spawn->size * 32;
	int box_x = mob->spawn->x * 32;
	int box_y = mob->spawn->y * 32;

	if (move % 2)
		x += PLAYER_SPEED * coef * delta_time;
	else
		y += PLAYER_SPEED * coef * delta_time;
	if (can_move(x, y, box_x, box_y, size)) {
		if (move % 2)
			x += PLAYER_SPEED * (coef * -2) * delta_time;
		else
			y += PLAYER_SPEED * (coef * -2) * delta_time;
	}
	mob->x = x;
	mob->y = y;
	return (0);
}

// #include <criterion/criterion.h>

// Test(check_mob_timeout, mob_move_passive, .timeout = 1)
// {
// 	srand(time(NULL));
// 	int i = 0;

// 	while ( i < 1000) {
// 		mob_move_passive();
// 		printf("Round %d done\n", i++);
// 	}
// }

// Test(mob_can_move, can_move)
// {
// 	int x = 100;
// 	int y = 50;
// 	int box_x = 0;
// 	int box_y = 0;
// 	int size = 100;

// 	cr_assert_eq(can_move(x, y, box_x, box_y, size), 0, "Failed to move");
// }