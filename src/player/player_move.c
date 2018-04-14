/*
** EPITECH PROJECT, 2018
** player_move.c
** File description:
** function to handle player mouvement
*/

#include "my_rpg.h"

static int can_move(object_info_t *map, player_info_t *player)
{
	double x = player->x;
	double y = player->y;

	if (x < 0 || x > 99 * 32 || y < 0 || y > 99 * 32)
		return 1;
	while (map) {
		if (map->collider != 1) {
			map = map->next;
			continue;
		}
		if (x >= map->x &&
		x <= map->x + 32 &&
		y >= map->y &&
		y <= map->y + 32) {
			return (1);
		}
		map = map->next;
	}
	return (0);
}

static int direction_modifier(int direction)
{
	if (direction == 4 || direction == 2)
		return (-1);
	return (1);
}

void player_move(game_global_t *game, double delta_time, int direction)
{
	double new_pos = PLAYER_SPEED * delta_time * direction_modifier(direction);
	double default_x = game->player->x;
	double default_y = game->player->y;
	object_info_t *map = game->info_map->first->first;

	game->player->direction = direction;
	if (direction == 1 || direction == 4) {
		game->player->y += new_pos;
	} else if (direction == 2 || direction == 3) {
		game->player->x += new_pos;
	}
	if (can_move(map, game->player)) {
		game->player->x = default_x;
		game->player->y = default_y;
	} else {
		game->player->moving = 1;
	}
}