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
	if (sfKeyboard_isKeyPressed(UP_KEY))
		player_move(game, delta_time, 4);
	if (sfKeyboard_isKeyPressed(DOWN_KEY))
		player_move(game, delta_time, 1);
	if (sfKeyboard_isKeyPressed(LEFT_KEY))
		player_move(game, delta_time, 2);
	if (sfKeyboard_isKeyPressed(RIGHT_KEY))
		player_move(game, delta_time, 3);
	if (sfKeyboard_isKeyPressed(sfKeyNum1))
		activate_spell(game, 0);
	if (sfKeyboard_isKeyPressed(sfKeyNum2))
		activate_spell(game, 1);
	if (sfKeyboard_isKeyPressed(sfKeyNum3))
		activate_spell(game, 2);
	if (sfKeyboard_isKeyPressed(sfKeyNum4))
		activate_spell(game, 3);
}