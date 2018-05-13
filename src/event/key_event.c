/*
** EPITECH PROJECT, 2018
** key_event
** File description:
** event for keys
*/

#include "spells.h"
#include "my_rpg.h"

void key_event(game_global_t *game, double delta_time)
{
	if (sfKeyboard_isKeyPressed(UP_KEY))
		player_move(game, delta_time, up);
	if (sfKeyboard_isKeyPressed(DOWN_KEY))
		player_move(game, delta_time, down);
	if (sfKeyboard_isKeyPressed(LEFT_KEY))
		player_move(game, delta_time, left);
	if (sfKeyboard_isKeyPressed(RIGHT_KEY))
		player_move(game, delta_time, right);
	if (sfKeyboard_isKeyPressed(SPELL_1))
		activate_spell(game, move_speed);
	if (sfKeyboard_isKeyPressed(SPELL_2))
		activate_spell(game, simple_attack);
	if (sfKeyboard_isKeyPressed(SPELL_3))
		activate_spell(game, double_attack);
	if (sfKeyboard_isKeyPressed(SPELL_4))
		activate_spell(game, circular_attack);
}