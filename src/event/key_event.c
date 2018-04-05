/*
** EPITECH PROJECT, 2018
** key_event
** File description:
** event for keys
*/

#include "my_rpg.h"
void player_move(game_global_t *game, double delta_time, int direction);

void key_event(game_global_t *game, double delta_time)
{
	if (sfKeyboard_isKeyPressed(sfKeyW)) {
		// game->player->y -= PLAYER_SPEED * (delta_time);
		// game->player->direction = 4;
		// game->player->moving = 1;
		player_move(game, delta_time, 4);
	}
	if (sfKeyboard_isKeyPressed(sfKeyS)) {
		player_move(game, delta_time, 1);
	}
	if (sfKeyboard_isKeyPressed(sfKeyA)) {
		player_move(game, delta_time, 2);
	}
	if (sfKeyboard_isKeyPressed(sfKeyD)) {
		player_move(game, delta_time, 3);
	}
}