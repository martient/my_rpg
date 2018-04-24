/*
** EPITECH PROJECT, 2018
** event_pause_screen.c
** File description:
** function to hande pause screen events
*/

/*
** EPITECH PROJECT, 2018
** event_start_screen.c
** File description:
** function to start screen events
*/

#include "my_rpg.h"

static int check_play_click(game_global_t *game, sfMouseButtonEvent event)
{
	sfVector2f position = {game->width / 2 - (54 * 2), game->height / 2};

	if (event.button == sfMouseLeft)
		if (event.x > position.x && event.x < position.x + (54 * 4) &&
		event.y > position.y && event.y < position.y + (54 * 2))
			game_loop(game);
	return (0);
}

static void keyboard_press_event(game_global_t *game, sfKeyEvent event)
{
	if (event.code == sfKeyEscape)
		game_loop(game);
}


int event_pause_screen(game_global_t *game)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(game->window, &event)) {
		if (event.type == sfEvtClosed) {
			sfRenderWindow_close(game->window);
			return (0);
		}
		if (event.type == sfEvtResized)
			update_screen_size(game);
		if (event.type == sfEvtKeyPressed)
			keyboard_press_event(game, event.key);

	}
	return (0);
}