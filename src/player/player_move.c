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
	double y = player->y + 39;

	if (x < -10 || x > 99 * 32 || y < 10 || y > 100 * 32)
		return 1;
	while (map) {
		if (map->collider != 1) {
			map = map->next;
			continue;
		}
		if (x <= (map->x * 32) + 20 &&
		x + 25 >= (map->x * 32) &&
		y <= (map->y * 32) + 32 &&
		y >= (map->y * 32)) {
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
	double tmp = PLAYER_SPEED * delta_time;
	double new_pos = tmp * direction_modifier(direction);
	double default_x = game->player->x;
	double default_y = game->player->y;
	object_info_t *map = game->info_map->first->first;

	game->player->direction = direction;
	if (direction == up || direction == down)
		game->player->y += new_pos * game->player->speed;
	else if (direction == left || direction == right)
		game->player->x += new_pos * game->player->speed;
	if (can_move(map, game->player)) {
		game->player->x = default_x;
		game->player->y = default_y;
	} else {
		game->player->moving = 1;
	}
}