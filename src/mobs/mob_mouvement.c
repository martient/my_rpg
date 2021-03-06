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
	y + 32 > player->y)
		return (1);
	return (0);
}

static int can_move(game_global_t *game, float x, float y, int box[3])
{
	int box_x = box[0];
	int box_y = box[1];
	object_info_t *map = game->info_map->first->first;

	if (x < box_x - 160 || x > box_x + 160 ||
	y < box_y - 160 || y > box_y + 160)
		return (0);
	if (x < 0 || x > 3200 || y < 0 || y > 3200)
		return (0);
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
	return (0);
}

int next_move(void)
{
	int coef = rand() % 1000;

	if (coef % 2)
		return (0);
	return (1);
}

//Passive
int mob_move_passive(game_global_t *game, mob_info_t *mob, double delta_time)
{
	float x = mob->x;
	float y = mob->y;
	int move = rand() % 4;
	int coef = next_move();
	int box[3] = {mob->spawn->x * 32, mob->spawn->y * 32,
	mob->spawn->size * 32};

	if (move == 0)
		x += (PLAYER_SPEED - 100) * coef * delta_time;
	if (move == 1)
		y -= (PLAYER_SPEED - 100) * coef * delta_time;
	if (move == 2)
		y += (PLAYER_SPEED - 100) * coef * delta_time;
	if (move == 3)
		x -= (PLAYER_SPEED - 100) * coef * delta_time;
	if (can_move(game, x, y, box)) {
		mob->x = x;
		mob->y = y;
	}
	return (0);
}