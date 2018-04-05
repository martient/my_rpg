/*
** EPITECH PROJECT, 2018
** key_event
** File description:
** event for keys
*/

#include "my_rpg.h"

void key_event(game_global_t *game, double delta_time)
{
	if (sfKeyboard_isKeyPressed(sfKeyW)) {
		game->player->y -= PLAYER_SPEED * (delta_time);
		game->player->direction = 4;
		game->player->moving = 1;
	}
	if (sfKeyboard_isKeyPressed(sfKeyS)) {
		game->player->y += PLAYER_SPEED * delta_time;
		game->player->direction = 1;
		game->player->moving = 1;
	}
	if (sfKeyboard_isKeyPressed(sfKeyA)) {
		game->player->x -= PLAYER_SPEED * delta_time;
		game->player->direction = 2;
		game->player->moving = 1;
	}
	if (sfKeyboard_isKeyPressed(sfKeyD)) {
		game->player->x += PLAYER_SPEED * delta_time;
		game->player->direction = 3;
		game->player->moving = 1;
	}
}