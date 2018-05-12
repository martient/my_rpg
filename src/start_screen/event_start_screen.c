/*
** EPITECH PROJECT, 2018
** event_start_screen.c
** File description:
** function to start screen events
*/

#include "my_rpg.h"

int check_play_click(game_global_t *game, sfMouseButtonEvent event)
{
	sfVector2f position = {game->width / 2 - (54 * 2), game->height / 2};

	if (event.button == sfMouseLeft)
		if (event.x > position.x && event.x < position.x + (54 * 4) &&
		event.y > position.y && event.y < position.y + (54 * 2))
			game_loop(game);
	return (0);
}

int event_start_screen(game_global_t *game)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(game->window, &event)) {
		if (event.type == sfEvtClosed) {
			exit_game(game);
			return (0);
		}
		if (event.type == sfEvtResized)
			update_screen_size(game);
		if (event.type == sfEvtMouseButtonPressed)
			check_play_click(game, event.mouseButton);
	}
	return (0);
}