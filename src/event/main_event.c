/*
** EPITECH PROJECT, 2018
** main_event.c
** File description:
** event hub
*/

#include "my_rpg.h"

void keyboard_press_event(game_global_t *game, sfKeyEvent event)
{
	if (event.code == sfKeyI)
		game->inventory_show = (game->inventory_show == 0) ? 1 : 0;
}

int analyse_event(game_global_t *game)
{
	sfEvent event;
	double delta_time =
	sfClock_getElapsedTime(game->clock).microseconds / 1000000.0;

	spell_cooldown(game, delta_time);
	while (sfRenderWindow_pollEvent(game->window, &event)) {
		if (event.type == sfEvtClosed) {
			rpg_player_save(game->player);
			sfRenderWindow_close(game->window);
			return (0);
		}
		if (event.type == sfEvtResized)
			update_screen_size(game);
		if (event.type == sfEvtKeyPressed)
			keyboard_press_event(game, event.key);
	}
	obj_cooldown(game, delta_time);
	key_event(game, delta_time);
	sfClock_restart(game->clock);
	return (0);
}
