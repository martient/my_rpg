/*
** EPITECH PROJECT, 2018
** main_event.c
** File description:
** event hub
*/

#include "my_rpg.h"

int analyse_event(game_global_t *game)
{
	sfEvent event;
	double delta_time =
	sfClock_getElapsedTime(game->clock).microseconds / 100000.0;

	while (sfRenderWindow_pollEvent(game->window, &event)) {
		if (event.type == sfEvtClosed) {
			sfRenderWindow_close(game->window);
			return (0);
		}
		if (event.type == sfEvtResized)
			update_screen_size(game);
	}
	key_event(game, delta_time);
	sfClock_restart(game->clock);
	return (0);
}