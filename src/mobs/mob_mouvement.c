/*
** EPITECH PROJECT, 2018
** mob_mouvement.c
** File description:
** function to move mob
*/

#include "my_rpg.h"

int collide_player(game_global_t *game, float x, float y)
{
	player_info_t *player = game->player;

	if (x < player->x + 32 &&
	x + 32 > player->x &&
	y < player->y + 32 &&
	y + 32 > player->y) {
		printf("Touching Player\n");
		return (1);
	}
	return (0);
}

static int can_move(game_global_t *game, float x, float y, int box[3])
{
	int box_x = box[0];
	int box_y = box[1];
	int size = box[2];
	object_info_t *map = game->info_map->first->first;

	while (map) {
		if (x <= (map->x * 32) + 32 &&
		x + 39 >= (map->x * 32) &&
		y <= (map->y * 32) + 32 &&
		y >= (map->y * 32))
			return (1);
		map = map->next;
	}
	if (collide_player(game, x, y))
		return (1);
	if (x >= box_x + size && x <= box_x &&
	y >= box_y + size && y <= box_y)
		return (1);
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
int mob_move_passive(game_global_t *game, mob_info_t *mob, double delta_time)
{
	float x = mob->x;
	float y = mob->y;
	int move = rand() % 100;
	int coef = next_move();
	int box[3] = {mob->spawn->x * 32, mob->spawn->y * 32,
	mob->spawn->size * 32};

	if (move % 2)
		x += PLAYER_SPEED * coef * delta_time;
	else
		y += PLAYER_SPEED * coef * delta_time;
	if (can_move(game, x, y, box)) {
		if (move % 2)
			x += PLAYER_SPEED * (coef * -2) * delta_time;
		else
			y += PLAYER_SPEED * (coef * -2) * delta_time;
	}
	mob->x = x;
	mob->y = y;
	return (0);
}