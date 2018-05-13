/*
** EPITECH PROJECT, 2018
** mob_mouvement_provoked.c
** File description:
** function for enemy mouvement when its provoked by player
*/

#include "my_rpg.h"

static int is_player_close(game_global_t *game, mob_info_t *mob)
{
	player_info_t *player = game->player;

	if (!(player->x < (mob->x + 100) && player->x > (mob->x - 100)))
		return (0);
	if (!(player->y < (mob->y + 100) && player->y > (mob->y - 100)))
		return (0);
	return (1);
}

static int is_between_offset(float point, float position, float offset)
{
	if (position < (point + offset) && position > (point - offset))
		return (1);
	return (0);
}

static int move_towards_player(game_global_t *game,
mob_info_t *mob, double delta_time)
{
	player_info_t *player = game->player;

	if (is_between_offset(player->x, mob->x, 10) &&
	is_between_offset(player->y, mob->y, 10))
		return (0);
	if (is_between_offset(player->x, mob->x, 10) != 1) {
		if (player->x > mob->x)
			mob->x += PLAYER_SPEED * delta_time;
		else
			mob->x -= PLAYER_SPEED * delta_time;
	}
	if (is_between_offset(player->y, mob->y, 10) != 1) {
		if (player->y > mob->y)
			mob->y += PLAYER_SPEED * delta_time;
		else
			mob->y -= PLAYER_SPEED * delta_time;
	}
	return (1);
}

int mob_move_provoked(game_global_t *game, mob_info_t *mob, double delta_time)
{
	player_info_t *player = game->player;

	if (is_player_close(game, mob))
		move_towards_player(game, mob, delta_time);
	return (0);
}