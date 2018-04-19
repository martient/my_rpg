/*
** EPITECH PROJECT, 2018
** mob_mouvement.c
** File description:
** function to move mob
*/

#include "my_rpg.h"

static int can_move(int x, int y, int box_x, int box_y, int size)
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
	else
		return  (1);
}

//Passive
int mob_move_passive()
{
	int x = 16;
	int y = 2;
	int move = rand() % 100;
	int coef = next_move();
	int size = 1000;
	int box_x = 0;
	int box_y = 0;

	if (move % 2) {
		x += PLAYER_SPEED * coef;
	} else {
		y += PLAYER_SPEED * coef;
	}
	if (can_move(x, y, box_x, box_y, size)) {
		if (move % 2) {
			x += PLAYER_SPEED * (coef * -2);
		} else {
			y += PLAYER_SPEED * (coef * -2);
		}
	}
	return (0);
}

#include <criterion/criterion.h>

Test(check_mob_timeout, mob_move_passive, .timeout = 1)
{
	srand(time(NULL));
	int i = 0;

	while ( i < 1000) {
		mob_move_passive();
		printf("Round %d done\n", i++);
	}
}

Test(mob_can_move, can_move)
{
	int x = 100;
	int y = 50;
	int box_x = 0;
	int box_y = 0;
	int size = 100;

	cr_assert_eq(can_move(x, y, box_x, box_y, size), 0, "Failed to move");
}